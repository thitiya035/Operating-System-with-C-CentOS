#include <unistd.h>
#include <stdio.h>

int main( int argc, char *argv[]){
	char *who;
	int i;
	
	printf("\nstart function ... \n");
	
	if (fork()){
		who = "weerayut";
	}else{
		who = "child";
	}
	
	for( i = 0; i < 6; i++){
		printf("*fork1: %s\n", who);
	}
	
	exit(42);
}