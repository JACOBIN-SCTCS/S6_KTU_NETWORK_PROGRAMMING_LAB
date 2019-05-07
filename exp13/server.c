#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/sendfile.h>

void error_function(int k)
{
	if(k==-1)
	{
		printf("\n ERROR\n");
		exit(0);
	}
}

void main()
{
	int sockfd;
	struct sockaddr_in serv , temp ;
	int tmp;
	struct stat obj;
	int len,k ;
        int choice; 
	char rec[100];	
	char length[100];
	char buf[100];
	int filehandle;
	char filename[30];

	sockfd= socket(AF_INET,SOCK_STREAM,0);
	error_function(sockfd);
	
	memset(&serv,0,sizeof(serv));
	serv.sin_addr.s_addr = INADDR_ANY;
	serv.sin_family=AF_INET;
	serv.sin_port=3000;

	if(bind(sockfd,(struct sockaddr*)&serv, sizeof(serv))==-1)
	{
		printf("Error binding\n");

		exit(0);
	}
	if(listen(sockfd,5) ==-1)
	{
		printf("Error listening\n");
		exit(0);
	}


	len =sizeof(temp);
	tmp =accept(sockfd,(struct sockaddr*)&temp,&len);
	error_function(k);

	while(1)
	{
		k=recv(tmp,buf,100,0);
		error_function(k);
	        if(strcmp(buf,"LIST")==0)
		{
			system("ls -al > list.txt");
			filehandle = open("list.txt" , O_RDONLY);
			stat("list.txt",&obj);
			sprintf(length,"%d",(int) obj.st_size);
			k =send(tmp,length,strlen(length),0);
			error_function(k);
			k= sendfile(tmp,filehandle,NULL,obj.st_size);

			
		}
		else if(strcmp(buf,"LOAD")==0)
		{
			k =recv(tmp,buf,100,0);
			strcpy(filename,buf);
			stat(filename,&obj);
			filehandle = open(filename,O_RDONLY);
			if(filehandle==-1)
			{
				printf("NOO SUCH FILE\n");
				exit(0);
			}
			sprintf(length,"%d",(int)obj.st_size);
			printf("\n %s\n",length);
			k=send(tmp,length,strlen(length),0);
			sendfile(tmp,filehandle,NULL,obj.st_size);

		
		}
		break;
		
	}

	close(sockfd);

}

