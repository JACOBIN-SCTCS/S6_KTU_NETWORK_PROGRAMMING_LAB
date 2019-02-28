#include <stdio.h>
#include <sys/types.h>

int main()
{
	int pid1 ,pid2; 
	
	
	/*
		pid1 --->  CREATE FIRST PROCESS
		pid2 --->  CREATE SECOND PROCESS
	*/

	
	pid1= fork();
	pid2=fork();
	
	
	if(pid1 > 0 && pid2 >0)
	{
		/* THE ROOT PARENT PROCESS */		
		
		wait(NULL);
		printf("\nI am inside the parent process with process id : %d\n" ,getpid() );
	}
	else if(pid1 >0 && pid2 ==0)
	{	
		/* THE CHILD OF PARENT PROCESS AFTER SECOND FORK */

		wait(NULL);
		printf("\nI am inside a child process  with process id : %d and parent process id : %d \n" ,getpid(),getppid() );
	
	}
	else if(pid1 ==0 && pid2 >0)
	{	
		/*THE CHILD PROCESS WHICH BECOMES A PARENT OF ANOTHER PROCESS*/

		wait(NULL);
		printf("\nI am inside a child process  with process id : %d and parent process id : %d \n" ,getpid(),getppid() );
	
	}
	else if(pid1 ==0 && pid2 ==0)
	{	
		/*THE CHILD OF THE CHILD PROCESS*/
		
		printf("\nI am inside a child process  with process id : %d and parent process id : %d \n" ,getpid(),getppid() );
	
	}
	
}
