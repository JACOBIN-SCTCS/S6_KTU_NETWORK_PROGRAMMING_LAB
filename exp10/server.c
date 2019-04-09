#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

void main()
{

	char buffer[30];
	int k ,sockfd,len;
	int childpid;
	struct sockaddr_in servaddr ;


	memset(&servaddr,0,sizeof(servaddr));
	sockfd = socket(AF_INET,SOCK_STREAM ,0);
	if(sockfd<0)
	{
		printf("Error");
		exit(0);
	}
	servaddr.sin_family=AF_INET;
	servaddr.sin_port = 3000;
	servaddr.sin_addr.s_addr =INADDR_ANY;

	if(bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr))!=0)
	{
		printf("Bind Failed");
		exit(0);
	}
	if(listen(sockfd,8) !=0)
	{
		printf("\nListen Failed");
		exit(0);
	}

	while(1)
	{
		len = sizeof(cli);
		//acc =accept(sockfd,(struct sockaddr*)&cli,&len);
		if( (childpid=fork())==0)
		{
			struct sockaddr_in cli;
			int acc =accept(sockfd,(struct sockaddr*)&cli,&len);
			close(sockfd);
			while(1)
			{
				recv(acc,buffer,30,0);
				printf("\n%s",buffer);
				send(acc,buffer,strlen(buffer),0);
				bzero(buffer,sizeof(buffer));
			}
		}
	}
	close(acc);
}
