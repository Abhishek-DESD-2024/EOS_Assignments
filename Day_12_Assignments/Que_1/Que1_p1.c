#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int c_fd,s_fd,cnt1,cnt2,num1,num2,res;
	c_fd = open("/tmp/one_fifo2",O_WRONLY);
	if(c_fd < 0)
	{
		perror("open() failed");
		_exit(1);
	}

	printf("Enter 2 numbers : ");
	scanf("%d %d",&num1,&num2);

	cnt1 = write(c_fd,&num1,sizeof(num1));
	cnt2= write(c_fd,&num2,sizeof(num2));

	printf("Numbers Written In File.\n");
//	printf("Bytes written are %d.\n",cnt1);
//	printf("Bytes written are %d.\n",cnt2);

	close(c_fd);


	s_fd = open("/tmp/one_fifo3",O_RDONLY);
	if(s_fd < 0)
	{
		perror("open() failed");
		_exit(1);
	}

	cnt1 = read(s_fd,&res,sizeof(res));
	printf("Result = %d\n",res);
	close(s_fd);
	return 0;
}


