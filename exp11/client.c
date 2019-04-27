#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>

void main()
{
	int sockfd,k;
	struct sockaddr_in client;
	char buffer[100];
	int len;
	sockfd= socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd==-1)
	{
		printf("Error creating a socket");
		exit(0);
	}
	client.sin_addr.s_addr = INADDR_ANY;
	client.sin_port=3000;
	client.sin_family=AF_INET;
	k=connect(sockfd,(struct sockaddr*)&client,sizeof(client));
	if(k==-1)
	{
		exit(0);

	}
	strcpy(buffer,"TIME");
	k =sendto(sockfd,buffer,sizeof(buffer),0,(struct sockaddr*)&client, sizeof(client) );
	if(k==-1)
	{
		exit(0);
	}
	len =sizeof(client);
	k =recvfrom(sockfd,buffer,100,0,(struct sockaddr*)&client,&len);
	printf("\n%s ",buffer);
	close(sockfd);
}
