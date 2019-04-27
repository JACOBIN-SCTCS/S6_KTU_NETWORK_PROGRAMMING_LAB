// SMTP CLINET
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<netinet/in.jh>


void main()
{
	char buf[100];
	int k;
	char msg[100];
	int sockfd;
	struct sockaddr_in addr1,addr2;
	sockfd =socket(AF_INET,SOCK_STREAM,0);
	if(sockfd==-1)
	{
		printf("\n Error\n");
		exit(0);
	}
	addr1.sin_family=AF_INET;
	addr1.sin_addr.s_addr= INADDR_ANY;
	addr1.sin_port=3001;

	k= bind(sockfd,(struct sockaddr*)&addr1,sizeof(addr1));
	if(k==-1)
	{
		printf("BINDING ERROR\n");
		exit(0);
	}

	k =listen(sockfd,5);
	if(k==-1)
	{
		printf("LISTEN FAILED\n");
		exit(0);
	}
	len = sizeof(addr2);
	addr2 = accept(sockfd,(struct sockaddr*)&addr2 ,&len);
	while(1)
	{

		k =recv(addr2,buf,100,0);
}
