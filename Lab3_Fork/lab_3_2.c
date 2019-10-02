#include<unistd.h>
#include<stdio.h>

int main(int argc, char *argv[]){
	int i ;
	char *who;
	int n;
	
	if( fork() ){
		who = "weerayut";
		n  	= 2;
	} else {
		who = "chile";
		n 	= 1;
	}
	
	for( i = 1; i <= 10; ++i){
		fprintf( stdout, "*%2d. %7s: my pid = %6d, ppid = %6d\n",
		i, who, getpid(), getppid());
		fflush(stdout);
		sleep(n);
	}
	exit(0);
}
