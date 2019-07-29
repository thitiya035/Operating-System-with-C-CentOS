#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
    printf("%d", gitpid());
    if(fork()){
        printf("%d", gitpid());
    }
    
}