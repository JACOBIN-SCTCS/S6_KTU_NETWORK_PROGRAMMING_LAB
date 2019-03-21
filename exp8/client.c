// JACOB JAMES K (31) TCP CLIENT
#include <sys/socket.h>
#include <netinet/in.h>
#include<stdlib.h>
#include <stdio.h>
#include <string.h>


void main()
{
	char buf[100];  //Buffer to hold the data
	char message_got[40];
	int k , sock_desc;
 	struct sockaddr_in client; //Client

	memset(&client,0,sizeof(client)); //Assigning memory
	sock_desc = socket(AF_INET,SOCK_STREAM,0); //create a TCP socket
	if(sock_desc==-1)
	{
		printf("Creation Failed");
		exit(0); 
	}

	//SETTING THE PARAMETERS
	client.sin_family=AF_INET;
	client.sin_addr.s_addr = INADDR_ANY;
	client.sin_port =3001;

	//CONNECT TO SERVER
	k =connect(sock_desc ,(struct sockaddr*)&client ,sizeof(client));
	if(k==-1)
	{
		printf("Error connecting to server");
		exit(0);

	}

	//GETTING THE DATA
	printf("\nEnter the data to send ");
	scanf("%s",buf);

	//SENDING THE DATA OBTAINED FROM USER
	k=send(sock_desc ,buf,100,0);
	if(k==-1)
	{
		printf("\nError sending data\n");
		exit(0);
	}

	//Wait for acknowledgement from the  server
	read(sock_desc,message_got,sizeof(message_got));
	printf("MESSAGE FROM SERVER = %s\n",message_got);

	//CLOSE THE SOCKET
	close(sock_desc);

}
