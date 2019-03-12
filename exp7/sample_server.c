#include<stdio.h>
#include<sys/msg.h>

struct msgbuf
{
	int  mtype;
	char msgtext[100];
};

void main()
{
	int msgid;
	struct msgbuf msg = {mtype:1 , msgtext:"Hello"};

	msgid = msgget(3711,IPC_CREAT|0666);
	msgsnd(msgid,&msg , sizeof(msg),0);

}
