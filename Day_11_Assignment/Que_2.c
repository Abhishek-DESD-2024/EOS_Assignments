#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>


int main()
{

	int arr1[2],ret,ret1,ret2,s;
	int arr2[2];
	int n1, n2, num1, num2,res;
	int a,b,c,d,e,result;
	ret1 = pipe(arr1);//Pipe1 For Child
	ret2 = pipe(arr2);//Pipe2 For Parent

	if(ret1 < 0)
	{
		perror("pipe() failed");
		_exit(1);
	}

	if(ret2 < 0)
	{
		perror("pipe2() failed");
		_exit(2);
	}

	ret = fork();
	
	if(ret == 0)
	{
		//Child Jo Hai Data Ko Write Karega
		close(arr1[0]);//Pipe 1 ka read end band rahega
		close(arr2[1]);//Pipe 2 ka write end band rahega

		printf("Enter Two Numbers : ");
		scanf("%d %d", &n1 ,&n2);

		a=write(arr1[1],&n1,sizeof(n1));
		b=write(arr1[1],&n2,sizeof(n2));
		

		e=read(arr2[0],&result,sizeof(result));
		printf("Result = %d\n", result);

		close(arr1[1]);
		close(arr2[0]);
	}
	else
	{
		//Parent is reading the data so, parent ka write end band rahega
		close(arr2[0]);
		close(arr1[1]);

		printf("Waiting For Data:..\n");
		c=read(arr1[0],&num1,sizeof(num1));
		d=read(arr1[0],&num2,sizeof(num2));
		
		res = num1 + num2;

		write(arr2[1],&res,sizeof(res));
		
		close(arr1[0]);
		close(arr2[1]);
		
		waitpid(-1,&s,0);
	}
	return 0;
}

