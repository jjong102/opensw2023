#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *work(void *arg){
    printf("hello thread world!\n");
    return NULL;
}

int main(void){
    pthread_t mythread;
    pthread_create(&mythread, NULL, work, NULL);
    pthread_join(mythread, NULL);
    printf("Main thread!\n"); // main thread가 끝나면 work실행도 못해보고 끝나요! (pthread, )
    return 0;
}