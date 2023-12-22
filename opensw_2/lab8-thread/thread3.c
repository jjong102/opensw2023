#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM 10
volatile long long counter = 0; // 이 값은 다른 친구들도 건들 수 있기 때문에, 메모리에 두어라! (cash나 register에 넣지 마라.. -02 사용해서 gcc 할시..)
char is_running = 1;

void *work(void *arg){
    while(is_running){
        counter++;
    }
    return NULL;
}

int main(void){
    pthread_t mythread;
    pthread_create(&mythread, NULL, work, NULL);

    for(int i=0; i<NUM; i++){
        printf("counter: %lld\n", counter);
        sleep(1); 
    }
    is_running = 0;

    pthread_join(mythread, NULL);
    printf("Main thread!\n"); // main thread가 끝나면 work실행도 못해보고 끝나요! (pthread, )
    return 0;
}