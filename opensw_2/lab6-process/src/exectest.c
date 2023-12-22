#include <unistd.h>
#include <stdio.h>

int main(){
    char *new_argv[] = {"ls", "-l", NULL};
    printf("hello world\n");
    execve("/usr/bin/ls", new_argv, NULL); // 기존에 있던 process가 사라지고, (___)에 있는 코드가 들어와서 새로운 process가 된다.
    printf("goodbye world\n");

    return 0;
}