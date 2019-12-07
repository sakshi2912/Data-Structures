#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"header.h"

int main(int argc , char ** argv)
{
	clock_t start, end;
     	double cpu_time_used;
     
     	start = clock();
     
    
	int n;
	List *list = initialize();
	if(argc==1)
	{
	 	printf("Usage:%s <number of queens>\n\n",argv[0]);
		exit(0);
	}
	else
	{
	
		n = atoi(argv[1]);
		if(n>2)
		{
		List *board = createBoard(list , n);
		queen(board , n);
		printf("%d solutions found\n",count);
		}
		else
		printf("INVALID");
    		freelist(list);
	}
	end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time taken: %f seconds\n",cpu_time_used);
return 0;
}
