#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/sendfile.h>


void handlerror(int k)
{
	if(k==-1)
	{
	printf("Error \n");
	exit(0);
	}
}


void main()
{
	int sockfd;
	struct sockaddr_in client;
	struct stat obj;
	char buf[100];
	char command[100];
	int k,filehandle;
	int len;
	int size;
	int i=0;
	int sock2;

	sockfd= socket(AF_INET,SOCK_STREAM,0);
	handlerror(sockfd);

	client.sin_port=3000;
	client.sin_addr.s_addr =	INADDR_ANY;
	client.sin_family=AF_INET;

	k =connect(sockfd,(struct sockaddr*)&client,sizeof(client));
	while(1)
	{
		strcpy(buf,"LIST");
		send(sockfd,buf,100,0);
		recv(sockfd,)
		if(!strcmp(command,"LIST"))
		{
			system("ls -al >  temp.txt");
			i=0;
			stat("temp.txt", &obj);
			size=obj.st_size;
			send(sock2 , &size,sizeof(int),0);
			filehandle = open("temp.txt",O_RDONLY);
			sendfile(sock2,filehandle,NULL,size);
		}
	}
	close(sock2);
}

