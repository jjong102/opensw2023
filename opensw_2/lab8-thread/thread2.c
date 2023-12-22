#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_THREADS 100
void *work(void *arg){
    printf("hello thread world!\n");
    pthread_exit(NULL);
}

int main(void){
    pthread_t mythread[NUM_THREADS];
    for (int i=0; i<NUM_THREADS; i++){
        pthread_create(&mythread[i], NULL, work, NULL);
    }
    for (int i=0; i<NUM_THREADS; i++){
        pthread_join(mythread[i], NULL);
    }
    printf("Main thread!\n"); // main thread가 끝나면 work실행도 못해보고 끝나요! (pthread, )
    return 0;
}