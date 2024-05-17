#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int arr[2];
void sign_handler(int sig)
{
	close(arr[0]);
	close(arr[1]);
	_exit(0);
}

int main()
{	
	
	int ret;
	char ch = 'R';
	ret = pipe(arr);
	struct sigaction sa;
	memset(&sa,0,sizeof(struct sigaction));
	sa.sa_handler = sign_handler;
	ret = sigaction(SIGINT,&sa,NULL);
	int count = 0;
	if(ret < 0)
	{
		perror("sigaction() failed");
		_exit(0);
	}
	while(1)
	{
		write(arr[1],&ch,sizeof(ch));
		count++;
		printf("Bytes Written : %d\n",count);
	}
	return 0;
}



