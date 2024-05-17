#include <stdio.h>
#include <unistd.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <stdlib.h>

#define MQ_KEY		0x7532

typedef struct msg{
	long type;
	int arr[4];
}msg_t;

typedef struct rmsg{
	long type;
	int res[4];
}msg_t1;



int main()
{
	int mqid,ret,ret1,ret2,ret3,ret4,ret5,res,s;
	mqid = msgget(MQ_KEY, IPC_CREAT | 0666);
	if(mqid < 0)
	{
		perror("msgget() failed");
		_exit(1);
	}

	ret = fork();
	if(ret == 0)
	{
		msg_t m1;
		msg_t1 m4;
		m1.type = 2;
		printf("Enter 1st number:");
		scanf("%d",&m1.arr[0]);
		printf("Enter 2nd number:");
		scanf("%d",&m1.arr[1]);
		ret1 = msgsnd(mqid,&m1,sizeof(m1.arr[0]),0);
		ret2 = msgsnd(mqid,&m1,sizeof(m1.arr[1]),0);
		printf("Numbers Sent Successfully. :%d----%d\n",ret1,m1.arr[0]);
		printf("Numbers Sent Successfully. :%d----%d\n",ret2,m1.arr[1]);

		ret5 = msgrcv(mqid, &m4, sizeof(m4.res[0]),3,0);
		printf("Result = %d\n",res);
	}

	else
	{
		msg_t m2;
		msg_t1 m3;
		m3.type=3;
		printf("Waiting For message : \n");
		ret3 = msgrcv(mqid,&m2,sizeof(m2.arr[0]),2,0);
		ret4 = msgrcv(mqid,&m2,sizeof(m2.arr[1]),2,0);
		printf("Data Received Successfully \n");
		printf("Numbers Received Successfully. :%d---%d\n",ret3,m2.arr[0]);
		printf("Numbers Received Successfully. :%d---%d\n",ret4,m2.arr[1]);
		printf("Hello\n");
		m3.res[0] = m2.arr[0] + m2.arr[1];
		ret = msgsnd(mqid, &m3, sizeof(m3.res[0]),0);
		wait(&s);
	}

}














