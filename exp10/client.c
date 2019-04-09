#include<stdio.h>
#include<sys/socket.h>
#include <netinet/in.h>
#include<stdlib.h>
#include<string.h>


void main()
{

	int sockfd ,k;
	struct sockaddr_in client;
	char buffer[50];
	memset(&client,0,sizeof(client));


	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
	{
		printf("Error creating socket");
		exit(0);
	}

	client.sin_family =AF_INET;
	client.sin_addr.s_addr = INADDR_ANY;
	client.sin_port = 3000;

	k =connect(sockfd , (struct sockaddr*)&client,sizeof(client));
	if(k==-1)
	{
		printf("Error connecting");
		exit(0);
	}

	while(1)
	{
		scanf("%s",buffer);
		send(sockfd,buffer,strlen(buffer),0);
		if(strcmp(buffer,"exit")==0)
		{
			close(sockfd);
			exit(0);
		}
		if(recv(sockfd,buffer,50,0)<0)
		{
			printf("Error receiving");
		}
		else
		{
			printf("\n%s", buffer);
		}
	}
}
