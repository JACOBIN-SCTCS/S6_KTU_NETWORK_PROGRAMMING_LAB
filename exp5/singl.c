#include<stdio.h>
#include<stdlib.h>

void main()
{

	int fd[2];
	int pid; 
	char str[15],str2[15];
	
	printf("Enter the string to send from parent process to child process\n");
	scanf("%s",str);
	
	if(pipe(fd) < 0)
	{
		printf("Error creating a Pipe\n");
		return;
	}
	pid= fork();
	if(pid < 0)	
	{
		printf("Error creating process\n");
		exit(0);
	}
	else if(pid >0)
	{
		close(fd[0]);
		write(fd[1] , str  ,sizeof(str));
		printf("Parent process has sent  the message  %s to child process \n ",str);
		close(fd[1]);
		
	}	
	else
	{
		close(fd[1]);
		read(fd[0] , str2  ,sizeof(str2));
		printf(" child process has got message %s\n ",str2);
		close(fd[0]);
		
	}
}

