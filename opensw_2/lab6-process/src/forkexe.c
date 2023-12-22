#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
    if ( fork() == 0 ){ //child process
        char *new_argv[] = {"ls", "-l", NULL};
        execve("/usr/bin/ls",new_argv, NULL); // 0반환
        printf("%lu\n", (unsigned long)getpid());
        exit(123); // execve를 하는 순간 이 코드는 실행이 안됨.
    } 
    else { //parent process
        int status;
        pid_t k = wait(&status); // 0이 return됨
        printf("%lu\n", (unsigned long)k);
        if (WIFEXITED(status)){
            printf("child exit code: %d\n", WEXITSTATUS(status));
        }
    }
    
    return 0;
}