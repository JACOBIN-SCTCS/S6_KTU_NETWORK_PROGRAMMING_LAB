#include<stdio.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

void main()
{
	
	int sockfd;
	int k,len;
	struct sockaddr_in servaddr;
	char buf[100];
	char domain[10];
	int m=0;
	int i =0,j;

	memset(&servaddr,0,sizeof(servaddr));
	sockfd = socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd==-1)
	{

		printf("SOCKET CREATION FAILED\n");
		exit(0);
	}
	servaddr.sin_family =AF_INET;
	servaddr.sin_addr.s_addr= INADDR_ANY;
	servaddr.sin_port=3000;


	k =bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	if(k==-1)
	{
		printf("\nBINDING FAILED");
		exit(0);
	}
	len=sizeof(servaddr);
	k =recvfrom(sockfd,buf,sizeof(buf),0,(struct sockaddr*)&servaddr,&len);
	if(k==-1)
	{
		printf("Error receiving \n");
		exit(0);
	}
	
	i=j=0;

	
	while(i<strlen(buf))
	{
		if(buf[i]=='@')
		{
			for(j=i+1;j<strlen(buf);++j)
			{
				domain[m++] = buf[j];
			
			}
			domain[m]='\0';
			break;
		}
		++i;
	}
	

	printf("\n DOMAIN VERFIED %s\n",domain);
	k= recvfrom(sockfd,buf,sizeof(buf),0,(struct sockaddr*)&servaddr,&len);


	
	printf("\n FROM :%s\n",buf);
	printf("\n MESSAGE BODY\n");
	strcpy(buf,"");
	while(strcmp(buf,":EXIT")!=0)
	{
		k=recvfrom(sockfd,buf,sizeof(buf),0,(struct sockaddr*)&servaddr,
				&len
				);
		if(strcmp(buf,":EXIT")==0)
			continue;
		
		printf("%s",buf);
	}

	close(sockfd);
}
