#include <unistd.h>
#include <stdio.h>
     
int main()
{
	int n1,m=0,n=0,i,j,k,sum=0;
	int a[10][10],b[10][10],c[10][10];

	printf("\n\tCP Matrix Multiplication and Addition\n");
	printf("\n\t-------------------------------------\n");

        printf("Enter no. of rows and cols:\n");
        scanf("%d%d",&m,&n);
       
        printf("Enter two matrices...\n\nA:\n");
        for(i = 0 ; i  < m ; i++)
            for(j = 0; j < n; j++)
                scanf("%d",&a[i][j]);
       
        printf("\n\nB:\n");
        for(i = 0 ; i  < m ; i++)
            for(j = 0; j < n; j++)
                scanf("%d",&b[i][j]);
        printf("\n");
        printf("\n");
        n1 = fork();
        if(n1 > 0)
        {   
	    sleep(1);
            printf("\nParent Process  \nMatrix Addition...\n");
            for(i = 0 ; i  < m ; i++)
                for(j = 0; j < n; j++)
                    c[i][j]=a[i][j]+b[i][j];
            for(i = 0 ; i  < m ; i++)
            {   
		printf("\n");
                for(j = 0; j < n; j++)
                printf("%d\t",c[i][j]);
       
            }
     
        }
        else if(n1 == 0)
        {
            printf("Child process \nMatrix Multiplication...\n");
            for(i = 0 ; i  < m ; i++)
                for(j = 0; j < n; j++)
                {
                    sum=0;
                    for(k = 0;k < m;k++)
                        sum+=a[i][k]+b[k][j];
                    c[i][j] = sum;
                }
             for(i = 0 ; i  < m ; i++)
             {   
		printf("\n");
                for(j = 0; j < n; j++)
                printf("%d\t",c[i][j]);
       
            }
     
        }
}

