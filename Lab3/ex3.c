#include <stdio.h>
#include <unistd.h> /* contains fork prototype */
main(void)
{
	printf("\n 1. Here I am just before first forking statement\n");
	fork();
	
	printf("\n 2. Here I am just after first forking statement\n");
	fork();
	
	printf("\n 3. Here I am just after second forking statement\n");
	printf("  -- Hello World from process %d!\n", getpid());
}
