// JACOB JAMES K (TIME SERVER APPLICATION SERVER ) 
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<time.h>

void main()
{
	int sockfd;
	struct sockaddr_in server ;
	int k;
	time_t t;
	char buff[1024];
	char buffer[100];
	char curr_time[50];
	int len;
	sockfd =socket(AF_INET,SOCK_DGRAM ,0);
	if(sockfd==-1)
	{
		printf("\n SOCKET CREATION FAILED");
		exit(0);
	}
	server.sin_port=3000;
	server.sin_addr.s_addr= INADDR_ANY;
	server.sin_family =AF_INET;


	if(bind(sockfd,(struct sockaddr*)&server,sizeof(server)) < 0)
	{
		printf("ERROR BINDING");
		exit(0);
	}

	len = sizeof(server);
	k=recvfrom(sockfd,buffer,100,0,(struct sockaddr*)&server , &len);
	if(k==-1)
	{
		printf("Error recevin\n");
		exit(0);
	}
	if(strcmp(buffer,"TIME")==0)
	{
		t =time(NULL);
		snprintf(buff,sizeof(buff),"%24s\r\n",ctime(&t));
		k=sendto(sockfd,buff,sizeof(buff),0,(struct sockaddr*)
		&server ,sizeof(server)
		);
	}
	close(sockfd);


}
