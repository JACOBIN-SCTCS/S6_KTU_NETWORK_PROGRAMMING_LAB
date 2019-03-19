// JACOB JAMES K (31) PROGRAM 7 .IPC MESSAGE QUEUE
#include <stdio.h>
#include <sys/msg.h>
#include <string.h>


struct msgbuf
{
        long mtype;
        char message[100];
} ;


void main()
{
	int msgid;
	struct msgbuf msg1 , msg2;
	struct msgbuf msg3;

	char mess[40];

	//CREATE  A MESSAGE QUEUE
	msgid =msgget(3712,IPC_CREAT|0666);

	//RECEIVE MESSAGES FROM CLIENTS
	msgrcv(msgid,&msg1,sizeof(msg1),1,0);
 	msgrcv(msgid,&msg2,sizeof(msg2),2,0);

	printf("Client1 message = %s\n",msg1.message);
	printf("Client2 message = %s\n",msg2.message);

	//CONCATENATING MESSAGES
	msg3.mtype =3;
	strcpy(mess ,msg1.message);
        strcat(mess,msg2.message);
        strcpy(msg3.message , mess);

	printf("\nMESSAGE = %s",mess);
	//MESSAGE TO SEND TO CLIENT
	msgsnd(msgid,&msg3,sizeof(msg3),0);
	printf("\nSERVER HAS SEND DATA \n");
	//DETACH SHARED MEMORY
	msgctl(msgid,IPC_RMID,NULL);
	//return 0;

}

/*

OUTPUT
________________________________
Client has send the messages
Client has got the message Hello World 
*/
