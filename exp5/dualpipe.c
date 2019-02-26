#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>


void main(){
	int pid ;
    	int fd1[2] , fd2[2];
	
	char str1[30],str2[30],str3[30],str4[30];

	
	strcpy(str1,"Hello , Child Process\n");

	strcpy(str3,"Hello , Parent Process\n");

	if(pipe(fd1)<0  || pipe(fd2)<0)
	{
		printf("Error creating  a pipe\n");
		return ; 

	}
	pid = fork();

	if(pid<0)
	{
		printf("Error creating a process\n");
		exit(0);

	}
	else if(pid>0)
	{
		close(fd1[0]);
		close(fd2[1]);

		write(fd1[1], str1, sizeof(str1) );

		printf("Parent has sent message\" %s \" to child\n",str1);
	       read(fd2[0],str4,sizeof(str4));
       	      printf("Parent has recieved message \" %s \" from child\n",str4);
		close(fd1[1]);
  		close(fd2[0]);
	}
	else
	{


		  close(fd1[1]);
                close(fd2[0]);

                read(fd1[0], str2, sizeof(str2) );

                printf("Child  has recieved  message\" %s \" from parent\n",str2);
               write(fd2[1],str3,sizeof(str3));
              printf("Child  has sent message \" %s \" to parent\n",str3);
                close(fd1[0]);
                close(fd2[1]);

	}
	
		
}
