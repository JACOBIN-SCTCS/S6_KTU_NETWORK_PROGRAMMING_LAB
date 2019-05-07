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
	struct sockaddr_in temp ,server;
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

	temp.sin_port=3000;
	temp.sin_addr.s_addr =	INADDR_ANY;
	temp.sin_family=AF_INET;

	k =bind(sockfd,(struct sockaddr*)&temp,sizeof(temp));
	handlerror(k);

	k =listen(sockfd,5);
	handlerror(k);

	len =sizeof(server);

	sock2= accept(sockfd,(struct sockaddr*)&server,&len);
	while(1)
	{
		recv(sock2,buf,100,0);
		sscanf(command,"%s",buf);
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

