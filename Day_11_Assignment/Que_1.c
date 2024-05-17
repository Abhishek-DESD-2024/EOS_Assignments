#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
	int ret,s,fd;
	ret = fork();
	if(ret == 0)
	{
		fd = open("in.txt", O_RDONLY);
		dup2(fd,0);
		execlp("wc","wc",NULL);
	}

	else
	{
		waitpid(-1,&s,0);
	}
}

