// thread 1개당 50000을 증가 시키는 프로그램

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 3
long long counter = 0;
pthread_mutex_t counter_lock = PTHREAD_MUTEX_INITIALIZER; // 열쇠 만들기

void *work(void *arg){
    pthread_mutex_lock(&counter_lock); // 화장실 문 잠그기
    for(int i=0; i<50000; i++){
        counter++;
    }
    pthread_mutex_unlock(&counter_lock); // 화장실 문 열기
    return NULL;
}

int main(void){
    pthread_t mythread[NUM_THREADS];
    
    for (int i=0; i<NUM_THREADS; i++){
        pthread_create(&mythread[i], NULL, work, NULL);
    }
    
    for (int i=0; i<NUM_THREADS; i++){
        pthread_join(mythread[i], NULL);
    }

    printf("counter: %lld\n", counter); // main thread가 끝나면 work실행도 못해보고 끝나요! (pthread, )
    return 0;
}