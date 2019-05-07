#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<string.h>
#include<sys/sendfile.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

void error_function(int k)
{
	if(k==-1)
	{
		printf("\nERROR \n");
		exit(0);
	}
}

void main()
{
	int sockfd,k;
	char buf[100];
	char length[100];
	char filename[40];
	int ch,l ;
	int len;
	int c =0;
	int filehandle;
	struct sockaddr_in client;
	char fil[100];

	sockfd = socket(AF_INET,SOCK_STREAM,0);
	error_function(sockfd);
	client.sin_family=AF_INET;
	client.sin_addr.s_addr = INADDR_ANY;
	client.sin_port=3000;

	k=connect(sockfd,(struct sockaddr*)&client,sizeof(client));
	error_function(k);

	while(1)
	{
		printf("\n1:LIST \n 2:LOAD \n 3:exit\n");
	       	scanf("%d",&ch);
		if(ch==1)
		{
			strcpy(buf,"LIST");
			filehandle =open("list2.txt",O_RDWR|O_CREAT,0700);
			k=send(sockfd,buf,strlen(buf),0);
			error_function(k);
			k =recv(sockfd,length,100,0);
			len=atoi(length);
			c=0;
			while(c<len)
			{
				l =read(sockfd,fil,100);
				if(l==0)
				break;
				write(filehandle,fil,100);
				c+=l;
			}
			system("cat list2.txt");
			close(filehandle);
		}
		else if(ch==2)
		{
			strcpy(buf,"LOAD");
			k =send(sockfd,buf,strlen(buf),0);
			error_function(k);
			filehandle= open("list3.txt",O_RDWR|O_CREAT,0700);
			printf("\nEnter Filename\n");
			scanf("%s",filename);
			k =send(sockfd,filename,strlen(filename),0);

			k=recv(sockfd,length,100,0);
			len=atoi(length);
			c=0;
			while(c<len)
			{
				l=read(sockfd,fil,100);
				if(l==0)
					break;
				write(filehandle,fil,strlen(fil));
				c+=l;
			}
			system("cat list3.txt");
		


		}
		else 
		{
			exit(0);
		}

	}


close(sockfd);
}
