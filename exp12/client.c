
// SMTP CLIENT (JACOB JAMES K) ROLL NO :31

#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

void main()
{
	int sockfd;
	int k;
	char buf[100];
	struct sockaddr_in client;
	memset(&client,0,sizeof(client));

	sockfd= socket(AF_INET,SOCK_DGRAM ,0);
	if(sockfd==-1)
	{
		printf("ERROR CREATING A SOCKET\n");
		exit(0);
	}
	
	client.sin_family= AF_INET;
	
	client.sin_addr.s_addr = INADDR_ANY;
	client.sin_port=3000;
	
	printf("\nMAIL TO:");
	scanf("%s",buf);
	k=sendto(sockfd,buf,sizeof(buf),0 , (struct sockaddr*)&client,sizeof(client));
	if(k==-1)
	{
		printf("ERROR\n");
		exit(0);
	}

	printf("\nFROM :");
        scanf("%s",buf);
        k=sendto(sockfd,buf,sizeof(buf),0 , (struct sockaddr*)&client,sizeof(client));
	printf("\nMESSAGE BODY :");
	while(strcmp(buf,":EXIT")!=0)
	{
		scanf("%s",buf);
		k=sendto(sockfd,buf,sizeof(buf),0,(struct sockaddr*)&client,sizeof(client));
	}

	close(sockfd);
}
