#include<stdio.h>
#include<sys/msg.h>

struct msgbuf
{
	long mtype;
	char message[100];
} ;

int main()
{
	struct msgbuf msg1 = { mtype: 1 , message:"Hello "};
	struct msgbuf msg2 = { mtype: 1 , message:"World "};
	struct msgbuf msg3;
	int msgid;
	msgid = msgget(3712,IPC_CREAT|0666);
	msgsnd(msgid,&msg1,sizeof(msg1),0);
	msgsnd(msgid,&msg2,sizeof(msg2),0);
	printf("Client has send the messages\n");

	msgrcv(msgid,&msg3,sizeof(msg3),1,0);
	printf("%s\n",msg3.message);
	msgctl(msgid,IPC_RMID,NULL);

	return 0;

}
