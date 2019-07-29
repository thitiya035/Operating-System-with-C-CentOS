#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

void main( ){
    printf("Hello\n");

    while(1){
        printf("while :*\n");
        fflush(stdout); 
        sleep(3);
    }
}