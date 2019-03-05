
// JACOB JAMES K  (31) SENDER PROCESS FOR SHARED MEMORY
#include<stdio.h>
#include<sys/shm.h>

void main()
{
	int storage_addr; 
	char *addr;
	char expr[30]="4+3+2";     //EXPRESSION TO BE EVALUATED BY SERVER
	storage_addr = shmget(3712,5,IPC_CREAT|0666);	//CREATE STORAGE_ADDR
	addr =shmat(storage_addr,NULL,0);	//ATTACH TO ADDRESS SPACE OF THE CURRENT PROCESS
	printf("CLIENT HAS SEND EXPRESSION %s TO SHARED MEMORY\n",expr);
	sprintf(addr,"%s",expr);
	shmdt(addr);		 //DETACH SHARED_MEMORY FROM THE PROCESS
}
/*
OUTPUT
__________________________________

CLIENT HAS SEND EXPRESSION 4+3+2 TO SHARED MEMORY

*/
