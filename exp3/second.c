#include <stdio.h>
#include <stdlib.h>

int main()
{
	
	int m ,n,p,q,i,j,k;
	int pid ; 
	int A[30][30] , B[30][30],C[30][30];
	
		
	printf("Enter the dimensions of the first matrix \n");
	scanf("%d%d", &m , &n);

	printf("Enter the dimensions of the second matrix \n");
	scanf("%d%d", &p , &q);
	
	if (!((m==p) && (n==q) && (n==p)))
	{
		printf("Both operations cannot be done at the same time \n");
		exit(0);
	}
	
	
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
		
	pid = fork();
	if(pid < 0)
	{
		printf("Error creating child process \n");
		exit(0); 
	}
	else if (pid==0)
	{
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
	{	wait(NULL);
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
