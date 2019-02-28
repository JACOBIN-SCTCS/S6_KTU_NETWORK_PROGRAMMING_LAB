// JACOB JAMES K  --31 -- IPC USING SHARED MEMORY
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/shm.h>
void main()
{
	int pid,storage_addr;
	char *addr ;
	char expr[30]="4+3+2\0" ; //EXPRESSION TO EVALUATE
  	char received[30];        //BUFFER WHICH THE PARENT PROCESS
	int result;


	storage_addr = shmget(3711,5,IPC_CREAT|0666);
	pid = fork();


	addr = shmat(storage_addr , NULL,0);
	if(pid<0)
	{
		printf("ERROR CREATING A CHILD PROCESS \n");
		return;
	}
	else if(pid==0)
	{
		sprintf(addr , "%s",expr);
	}
	else
	{
		wait(NULL);
		sscanf(addr,"%s",received);
		printf("%s",received);

		result  = (int)(received[0] + received[3] + received[5] ) ;
		printf("RESULT = %d" , result);
	}
	shmdt(addr);
}
