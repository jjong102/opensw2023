#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
    if ( fork() == 0 ){ //child process
       printf("자식 : %d\n",getpid());

    } 
    else { //parent process
        
        printf("부모 : %d\n",getpid());
        wait(NULL);

    }    
    printf("누구 : %d\n",getpid());
    return 0;
}