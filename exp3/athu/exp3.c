#include<stdio.h>
main()
{
	int i;

	printf("\n\tParent and Clild Process\n");
	printf("\t------------------------\n\n");

	for(i=0;i<3;i++)
	{	
	   if(fork()==0)
	   {
	      printf("  Son pid %d from Parent pid %d\n\n",getpid(),getppid());
	      exit(0);
	   }
	}
	for(i=0;i<3;i++)
		wait(NULL);
}