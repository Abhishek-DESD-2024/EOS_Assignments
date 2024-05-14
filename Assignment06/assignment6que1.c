#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>



int main()
{
	int ret1,ret2,ret3,ret4,ret5,i,s;
	ret1=fork();
	if (ret1==0)
	{
		for(i=1;i<=5;i++){
			printf("ret1 count:%d\n",i);
			sleep(1);
		}
		_exit(0);
	}

	ret2=fork();
	if(ret2==0)
	{
		for(i=1;i<=5;i++){
			printf("ret2 count:%d\n",i);
			sleep(1);
		}
		_exit(0);
	}


	ret3=fork();
	if(ret3==0)
	{
		for(i=1;i<=5;i++){
			printf("ret3 count:%d\n",i);
			sleep(1);
		}
		_exit(0);

	}

	ret4=fork();
	if(ret4==0)
	{
		for(i=1;i<=5;i++){
			printf("ret4 count:%d\n",i);
			sleep(1);
		}
		_exit(0);
	}

	ret5=fork();
	if(ret5==0)
	{
		for(i=1;i<=5;i++)
		{
			printf("ret5 count:%d\n",i);
			sleep(1);
		}
		_exit(0);
	}
	else
	{
		for(int i=0;i<5;i++){
			printf("PArent %d\n",i);
			sleep(1);
			}
	}

		for(i=1;i<=5;i++)
		{

			wait(&s);
			printf("child exit:%d\n",WEXITSTATUS(s));

		}
	return 0;
}
