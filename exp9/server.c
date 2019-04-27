//JACOB JAMES K (31) UDP SERVER
#include<stdio.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<string.h>

void main()
{

	int sockfd;
	struct sockaddr_in servaddr;
	int k;
	int len;

	char buffer[100];
	char servermessage[100];

	// CREATE MEMORY
	memset(&servaddr,0,sizeof(servaddr));

	//CREATE A SOCKET
	sockfd = socket(AF_INET,SOCK_DGRAM,0);


	// SETTING PROPERTIES
	servaddr.sin_family=AF_INET;
	servaddr.sin_port = 3000;
	servaddr.sin_addr.s_addr = INADDR_ANY;

	//BIND THE SERVER ON TO THE PORT
	if(bind(sockfd,(struct sockaddr*)&servaddr, sizeof(servaddr)) <0)
	{
		printf("Error binding\n");
		exit(0);
	}
	len =sizeof(servaddr);

	// GET MESSAGE FROM CLIENT
	k =recvfrom(sockfd,buffer,100,0,(struct sockaddr*)&servaddr,&len);
	if(k==-1)
	{
		printf("Error receiving\n");
	}
	printf("\n%s",buffer);


	//READ THE MESSAGE AND SEND TO  THE CLIENT
	printf("Enter message to be sent from server to client\n");
	scanf("%s",servermessage);
	k =sendto(sockfd,servermessage,sizeof(servermessage),0,(struct sockaddr*)&servaddr,sizeof(servaddr));
	if(k==-1)
	{
		printf("Error sending data");
		exit(0);
	}

	//CLOSE THE SOCKET
	close(sockfd);

}
