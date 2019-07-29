#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
    int PID;
    printf("\n1 PID => %d : %d : %d\n", PID, getpid(), getppid() );
    
    PID = fork();

    printf("\n2 PID => %d : %d : %d\n", PID, getpid(), getppid() );


}