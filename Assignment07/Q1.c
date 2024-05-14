#include<stdio.h>
#include<signal.h>


int main()
{	
	int pid, signum, ret;
	printf("To terminate process.\n");
	printf("Enter PID SIGNUM : ");
	scanf("%d %d", &pid, &signum);
	ret = kill(pid,signum);
	if(ret == 0) 
		printf("Given process terminated successfully..\n");
	
	else
		printf("Termination Failed");

	return 0;

}
