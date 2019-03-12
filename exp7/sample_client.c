#include<stdio.h>
#include<sys/msg.h>

struct msgbuf
{
	int  mtype;
	char msgtext[100];
}msg;

int  main()
{
	int msgid;
	msgid = msgget(3711,IPC_CREAT|0666);
	msgrcv(msgid,&msg , sizeof(msg),1,0);
	printf("%d",msg.mtype);
	msgctl(msgid,IPC_RMID,NULL);
	return 0 ;
}
