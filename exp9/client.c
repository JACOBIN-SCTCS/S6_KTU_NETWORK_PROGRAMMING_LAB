#include<stdio.h>
#include<sys/socket.h>
#include<string.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<sys/types.h>

void main()
{
	int sockfd,k;
	struct sockaddr_in client;
	int len;
	char buffer[50];
	char messagesent[50];

	memset(&client,0,sizeof(client));
	sockfd =socket(AF_INET,SOCK_DGRAM,0);

	client.sin_port=3000;
	client.sin_addr.s_addr = INADDR_ANY;
	client.sin_family=AF_INET;

	k=connect(sockfd,(struct sockaddr*)&client,sizeof(client));
	if(k==-1)
	{
		printf("Error connecting\n");
		exit(0);
	}
	printf("Enter message to send\n");
	scanf("%s",buffer);

	k =sendto(sockfd,buffer,sizeof(buffer) ,0,(struct sockaddr*)&client,sizeof(client));
	if(k==-1)
	{
		printf("Error sending data\n");
		exit(0);
	}
	printf("\n Message sent successfully");

	len = sizeof(client);
	k= recvfrom(sockfd,messagesent,100,0,(struct sockaddr*)&client,&len);
	printf("\nMessage from server = %s",messagesent);
	close(sockfd);
}
