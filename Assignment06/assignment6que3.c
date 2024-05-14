#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int ret ,s,i;
	i==1;
	while(1)
	{
		ret=fork();
		if(ret==0)
		{
			printf("child\n");
			_exit(0);
		}
		else if(ret== -1)
			break;

		else
			i++;
	}
	for(int j=0;j<=1;j++)
		wait(&s);

	printf("Maximum process created :%d\n",i);
}
