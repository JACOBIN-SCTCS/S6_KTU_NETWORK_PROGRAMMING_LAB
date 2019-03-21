// JACOB JAMES K (31) TCP CLIENT
#include <sys/socket.h>
#include <netinet/in.h>
#include<stdlib.h>
#include <stdio.h>
#include <string.h>


void main()
{
	char buffer[100];  //Buffer to hold the data
	int k ,sock_desc,acc_packet,len; 
	struct sockaddr_in server ,cli;

	//setting the memory
	memset(&server,0,sizeof(server));

	//creatinf the socket | connecting to it
	sock_desc = socket(AF_INET,SOCK_STREAM ,0);
	if(sock_desc==-1)
	{
		printf("Error creating connection\n");
		exit(1);
	}

	//SETTING THE PARAMETERS
	server.sin_family=AF_INET;
	server.sin_addr.s_addr =INADDR_ANY;
	server.sin_port=3001;


	//Binding the socket
	if(bind(sock_desc,(struct sockaddr*)&server,sizeof(server))!=0)
	{
		printf("Bind failed\n");
		exit(0);
	}
	//Listening to the socket
	if(listen(sock_desc,5)!=0)
	{
		printf("\nListen Failed");
		exit(0);

	}
	len =sizeof(cli);
	//receive packet from user
	acc_packet = accept(sock_desc,(struct sockaddr*)&cli , &len);

	read(acc_packet,buffer,sizeof(buffer));

	//printing message got from client
	printf("\nSERVER HAS GOT MESSAGE=%s FROM CLIENT\n",buffer);

	//Write acknowledgement to the client
	write(acc_packet,"ACKNOWLEDGED" , sizeof("ACKNOWLEDGED"));
	close(sock_desc);
}
