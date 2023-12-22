#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    
    unsigned long pid;
    unsigned long ppid;
    pid =  (unsigned long)getpid();
    ppid = (unsigned long)getppid();

    printf("my pid : %lu\nmy ppid : %lu\n", pid, ppid);
    return 0;
}