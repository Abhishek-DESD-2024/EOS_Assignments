#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{	
	int c_fd,s_fd,cnt1,cnt2,num1,num2,cnt,res;
	c_fd = open("/tmp/one_fifo2",O_RDONLY);
	if(c_fd < 0)
	{
		perror("open() failed");
		_exit(1);
	}

	printf("Waiting For Data...\n");
	cnt1 = read(c_fd, &num1,sizeof(num1));
	cnt2 = read(c_fd, &num2,sizeof(num2));
	
	printf("Read From FiFo : %d bytes----%d\n",cnt1,num1);
	printf("Read From FiFo : %d bytes----%d\n",cnt2,num2);

	res = num1 + num2;
	
	s_fd = open("/tmp/one_fifo3",O_WRONLY);

	if(s_fd < 0)
	{
		perror("open() failed");
		_exit(1);
	}
	
	
	cnt = write(s_fd,&res,sizeof(res));
	
	close(c_fd);
	close(s_fd);
	return 0;
}



