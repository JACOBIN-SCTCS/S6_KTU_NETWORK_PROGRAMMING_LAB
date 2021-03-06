// (JACOB JAMES) 31 EXPT 3.B
#include <stdio.h>
#include <stdlib.h>

int main()
{
	
	int m ,n,p,q,i,j,k;
	int pid ; 

	/*

		IMPLEMENTING
		C =A+B
		C=A*B

	*/
	int A[30][30] , B[30][30],C[30][30];
	
	/*
		DIMENSIONS OF THE MATRIX WHICH ARE USED.

	*/
		
	printf("Enter the dimensions of the first matrix \n");
	scanf("%d%d", &m , &n);

	printf("Enter the dimensions of the second matrix \n");
	scanf("%d%d", &p , &q);
	

	/*
		CHECKING IF AN OPERATION IS POSSIBLE
	*/

	if (!((m==p) && (n==q) && (n==p)))
	{
		printf("Both operations cannot be done at the same time \n");
		exit(0);
	}
	
	/*

	INPUTTING THE MATRICES
	*/
	printf("\nEnter the first matrix \n");
	
	for ( i=0 ;i<m ;++i)
	{
		for(j=0 ;j<n; ++j)
		{
			scanf("%d", &A[i][j]);
		}
	}
	
	printf("\nEnter the second matrix \n");
	for ( i=0 ;i<p ;++i)
	{
		for(j=0 ;j<q; ++j)
		{
			scanf("%d", &B[i][j]);
		}
	}
	
	//CREATING A CHILD PROCESS
	pid = fork();
	if(pid < 0)
	{
		printf("Error creating child process \n");
		exit(0); 
	}
	
	else if (pid==0)
	{
		/* PERFORM MULTIPLICATION IN CHILD PROCESS */
		printf("\nI am inside a child process  with process id : %d and parent process id : %d \n" ,getpid(),getppid() );
		for ( i=0 ;i<m ;++i)
		{	
			for(j=0 ;j<q; ++j)
			{
				C[i][j]=0;
				for (k=0;k<n;++k)
				{
					C[i][j]+=A[i][k]*B[k][j];
				}
			}
		}
		printf("\n MATRIX OBTAINED FROM MULTIPLICATION\n");
		for ( i=0 ;i<m ;++i)
		{	printf("\n");
			for(j=0 ;j<q; ++j)
			{
			printf("%d\t", C[i][j]);
			}
		}
	}
	else
	{	
		/*PERFORM ADDITION IN PARENT PROCESS*/
		
		wait(NULL);
		printf("\nI am inside the parent process with process id : %d\n" ,getpid() );
		
		printf("\n MATRIX OBTAINED FROM ADDITION \n");	
		for ( i=0 ;i<p ;++i)
		{
			printf("\n");
			for(j=0 ;j<q; ++j)
			{
				C[i][j] = A[i][j] + B[i][j];
				printf("%d " ,C[i][j]);
			}
		}
		printf("\n");
		
	}
	
}


/*

OUTPUT
______________________________________________


Enter the dimensions of the first matrix 
2
2
Enter the dimensions of the second matrix 
2
2

Enter the first matrix 
1
2
3
4

Enter the second matrix 
5
6
7
8

I am inside a child process  with process id : 3290 and parent process id : 3288 

 MATRIX OBTAINED FROM MULTIPLICATION

19	22	
43	50	
I am inside the parent process with process id : 3288

 MATRIX OBTAINED FROM ADDITION 

6 8 
10 12 


*/
