// Jacob James 	K (31) SERVER PROCESS FOR SHARED MEMORY
#include<stdio.h>
#include<sys/shm.h>
void main()
{
	int storage_addr ;
	char *addr;
	int result=0;
	char received[30];

	storage_addr =shmget(3712,5,IPC_CREAT|0666);	//GET THE SHARED MEMORY
	addr =shmat(storage_addr,NULL,0);	//ATTACH TO THE ADDRESS SPACE
	sscanf(addr,"%s",received);	//READING FROM SHARED MEMORY
	printf("GOT THE EXPRESSION %s FROM SHARED MEMORY\n",received);
	//printf("%d",(int)received[2]);

	/*

	EVALUATING THE SHARED MEMORY
	*/
	result =received[0]-'0';
	result += received[2]-'0';
	result += received[4]-'0';

	//PRINT THE RESULT
	printf("\n RESULT = %d\n",result);
	shmdt(addr);	//DETACH THE SHARED MEMORY FROM THE PROCESS
}
/*
OUTPUT
______________________

GOT THE EXPRESSION 4+3+2 FROM SHARED MEMORY

 RESULT = 9


*/
