// FTP CLIENT JACOB JAMES K (31)

#include<sys/netinet.h>
#include<stdio.h>
#include<stdlb.h>
#include<string.h>
#include<sys/socket.h>

void main()
{
	struct sockaddr_in addr1 , addr2;
	int sockfd,k;
	int len;
	int filehandle;
	char buf[100];
	

	sockfd = socket(AF_INET,SOCK_STREAM ,0);
	if(sockfd==-1)
		{
			printf("Socket Creation Failed\n");
		}
	addr1.sin_family= AF_INET;
	addr1.sin_port =3000;
	addr1.sin_addr.s_addr = INADDR_ANY;
	
	k =bind(sockfd,(struct sockaddr*)&addr1,sizeof(addr1));
	if(k==-1)
		{
			printf("BIND FAILED\n");
		}
	k=listen(sockfd,5)
	if(k==-1)
		{
			printf("Listen Failed\n");
		}
	len =sizeof(addr2);  
	k= accept(sockfd,(struct sockaddr*)&addr2,&len);
	if(k==-1)
	{
		printf("Receive Failed\n");
	}
	read(sockfd,buf,sizeof(buf));
	if(strcmp(buf,"LIST")==0)
	{

		system("ls -al > list.txt");
		filehandle = open("list.txt","r");


	}

}
