#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>


int main(){
    if ( fork() == 0 ){ //child process
        printf("pid: %lu, ppid: %lu\n", (unsigned long)getpid(), (unsigned long)getppid());
        // for (int i = 0; i < 100; i++){
        //     printf("%d\n",i);
        // }
        exit(123);
    } 
    else { //parent process
        int status;

        printf("pid: %lu, ppid: %lu\n", (unsigned long)getpid(), (unsigned long)getppid());
        // for (int i = 100; i < 200; i++){
        //     printf("%d\n",i);
        // }
        wait(&status);
        if (WIFEXITED(status)){
            printf("child exit code: %d\n", WEXITSTATUS(status));
            printf("child exit code status: %d\n", status);
        }
    }
    
    return 0;
}