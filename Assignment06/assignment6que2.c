#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>


int main()
{

	int A,B,C,D, i ,s1,s2,s3,s4;
	A=fork();
	if(A==0)
	{
		B=fork();
		if(B==0)
		{
			C=fork();
			if(C==0)
			{
				D=fork();
				if(D==0)
				{
					printf("child D is child of child C\n");
					printf("Child of %d is %d\n",getppid(),getpid());
					_exit(0);

				}
				printf("Child C is Child of B\n");
				printf("child of %d is %d\n",getppid(),getpid());
				waitpid(D,&s1,0);
				_exit(0);
			}

			printf("Child B is Child of A\n");
			printf("child of %d is %d\n",getppid(),getpid());
			waitpid(C,&s2,0);
			_exit(0);
		}

		printf("Child B is Child of A\n");
		printf("child of %d is %d\n",getppid(),getpid());
		waitpid(B,&s1,0);
		_exit(0);
	}
	
	printf("Child A is Child of Main process\n");
	printf("child of %d is %d\n",getppid(),getpid());
	waitpid(A,&s1,0);


}
