// JACOB JAMES K (ROLL NO:31)  UDP CLIENT
#include<stdio.h>
#include<sys/socket.h>
#include<string.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<unistd.h>

void main()
{
	int sockfd,k;
	struct sockaddr_in client;
	int len;
	char buffer[50];
	char messagesent[50];
	//SET MEMORY FOR SOCKADDR_IN
	memset(&client,0,sizeof(client));
	sockfd =socket(AF_INET,SOCK_DGRAM,0);

	//SETTINGS FOR CLIENT
	client.sin_port=3000;
	client.sin_addr.s_addr = INADDR_ANY;
	client.sin_family=AF_INET;


	//CONNECT TO SOCKET
       //	k=connect(sockfd,(struct sockaddr*)&client,sizeof(client));
	//if(k==-1)
	///{
	//	printf("Error connecting\n");
	//	exit(0);
	//}

	//READING THE MESSAGE FROM THE CLIENT
	printf("Enter message to send\n");
	scanf("%s",buffer);


	//SEND MESSAGE TO SERVER
	k =sendto(sockfd,buffer,sizeof(buffer) ,0,(struct sockaddr*)&client,sizeof(client));
	if(k==-1)
	{
		printf("Error sending data\n");
		exit(0);
	}
	printf("\n Message sent successfully");

	//RECEIVE MESSAGE FROM THE SERVER
	len = sizeof(client);
	k= recvfrom(sockfd,messagesent,100,0,(struct sockaddr*)&client,&len);
	printf("\n\nMessage from server = %s",messagesent);

	//CLOSE THE SOCKET
	close(sockfd);
}
