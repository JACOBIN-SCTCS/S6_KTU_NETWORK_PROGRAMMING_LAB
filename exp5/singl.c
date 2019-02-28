// (JACOB JAMES K) 31 SINGLE PIPE
#include<stdio.h>
#include<stdlib.h>

void main()
{

	int fd[2];
	int pid; 
	char str[30],str2[30];
	
	//INPUTING THE STRING TO SEND TO CHILD
	printf("Enter the string to send from parent process to child process\n"); 
	scanf("%s",str);
	
	if(pipe(fd) < 0)
	{
		//ERROR CREATING A PIPE

		printf("Error creating a Pipe\n");
		return;
	}
	pid= fork();
	if(pid < 0)	
	{	// ERROR CREATING A PROCESS
		printf("Error creating process\n");
		exit(0);
	}
	else if(pid >0)
	{

		/*
			INSIDE THE PARENT PROCESS 
			CLOSE THE READEND AND WRITE USING write() system call
			CLOSE THE FILE

		*/
		close(fd[0]);
		write(fd[1] , str  ,sizeof(str));
		printf("Parent process has sent  the message  %s to child process \n ",str);
		close(fd[1]);
		
	}	
	else
	{

		/*
			INSIDE THE CHILD PROCESS 
			CLOSE THE WRITEEND AND READ USING read() system call
			CLOSE THE FILE

		*/
		close(fd[1]);
		read(fd[0] , str2  ,sizeof(str2));
		printf(" child process has got message %s\n ",str2);
		close(fd[0]);
		
	}
}


/*
OUTPUT
____________________

Enter the string to send from parent process to child process
HELLO CHILD
Parent process has sent  the message  HELLO to child process 
child process has got message HELLO


*/
