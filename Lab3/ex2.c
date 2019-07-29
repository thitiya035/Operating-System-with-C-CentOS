#include <stdio.h>
#include <unistd.h> /* contains fork prototype */
int main(void){
	int pid;
	printf("\n-------------------\n\nHello World!\n");
	printf("I am the parent process and pid is : %d .\n",getpid());
	printf("Here i am before use of forking\n\n");
	
	pid = fork();
	printf("\n-------------------\n");
	printf("\nHere I am just after forking\n");
	if (pid == 0)
		printf("\nI am the child process and pid is:%d.\n\n",getpid());
	else
		printf("\nI am the parent process and pid is:%d.\n",getpid());
}
