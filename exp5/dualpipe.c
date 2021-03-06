// JACOB JAMES K 31  DUAL PIPE
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>


void main(){
	int pid ;
    	int fd1[2] , fd2[2];
	
	char str1[30],str2[30],str3[30],str4[30];

	
	strcpy(str1,"Hello , Child Process\n");	 // MESSAGE TO BE SEND FROM PARENT TO CHILD

	strcpy(str3,"Hello , Parent Process\n"); // MESSAGE TO BE SEND FROM CHILD TO PARENT

	if(pipe(fd1)<0  || pipe(fd2)<0)
	{		
		//ERROR WHEN CREATING A PIPE
		printf("Error creating  a pipe\n");
		return ; 

	}
	//CREATING A CHILD PROCESS 
	
	pid = fork();

	if(pid<0)
	{
		//ERROR CREATING A CHILD PROCESS
		printf("Error creating a process\n");
		exit(0);

	}
	else if(pid>0)
	{	/*
		PARENT PROCESS
		
		*/
		
		close(fd1[0]); //CLOSE THE READEND OF THE PIPE1
		close(fd2[1]); // CLOSE THE WRITEEND OF THE PIPE2
		
		write(fd1[1], str1, sizeof(str1) ); //WRITE THROUGH PIPE1

		printf("Parent has sent message\" %s \"to child\n",str1);
	        read(fd2[0],str4,sizeof(str4));    //READ THROUGH PIPE2
       	        printf("Parent has recieved message \" %s \"from child\n",str4);
		
		close(fd1[1]);  //CLOSE THE FILES AFTER USE
  		close(fd2[0]);  //CLOSE THE FILES AFTER USE
	}
	else
	{
		/*
		CHILD PROCESS
		
		*/


		close(fd1[1]); //CLOSE THE WRITEEND OF THE PIPE1
                close(fd2[0]); //CLOSE THE READEND OF THE PIPE2

                read(fd1[0], str2, sizeof(str2) );  //READ THROUGH PIPE1

                printf("Child  has recieved  message\" %s \"from parent\n",str2);
                write(fd2[1],str3,sizeof(str3));   //WRITE THROUGH PIPE2
                printf("Child  has sent message \" %s \"to parent\n",str3);
                close(fd1[0]);   //CLOSE THE FILES AFTER USE
                close(fd2[1]);	 //CLOSE THE FILES AFTER USE
 
	}
	
		
}

/*

OUTPUT
________________
Parent has sent message" Hello , Child Process " to child
Child  has recieved  message" Hello , Child Process "from parent
Child  has sent message " Hello , Parent Process "to parent
Parent has recieved message " Hello , Parent Process "from child

*/
