#include <stdio.h>
#include <sys/msg.h>
#include <string.h>

struct msgbuf
{
        long mtype;
        char message[100];
} ;


int main()
{
	int msgid;
	struct msgbuf msg1 , msg2;

	msgid =msgget(3712,IPC_CREAT|0666);

	msgrcv(msgid,&msg1,sizeof(msg1),1,0);
 	msgrcv(msgid,&msg2,sizeof(msg2),1,0);

	strcat(msg1.message, msg2.message);
	msgsnd(msgid,&msg1,sizeof(msg1),0);
	printf("SERVER HAS SEND DATA \n");
	msgctl(msgid,IPC_RMID,NULL);
	return 0;

}

