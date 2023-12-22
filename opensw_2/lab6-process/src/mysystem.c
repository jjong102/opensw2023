#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int my_system(char *command){
    
    pid_t pid = fork();
    if ( pid == -1 ){
        perror("fork");
        return -999;
    }
    else if ( pid == 0 ) { // 자식 프로세스
        char *cmd = "/bin/sh";
        char *args[] = {"sh", "-c", command, NULL};
        execve(cmd, args, NULL);
        perror("execve");
        exit(123);
    } 
    else { // 부모 프로세스
        int status;
        wait(&status);
        if (WIFEXITED(status)) {
            return status;
        } 
        else {
            fprintf(stderr, "Child process did not exit normally\n");
            return -999;
        }
    }
}


int main(){
    int status;
    status = my_system("d");
    printf("exit code %d\n", WEXITSTATUS(status));
    return 0;
}