#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

struct two_double {
    double a;
    double b;
} data;

void sigint_handler(int signo){
    printf("Ouch!!! I got %d\n", signo);
}

void sigquit_handler(int signo){
    printf("Good bye!\n");
    exit(0);
}

void sigalarm_handler(int signo){
    //printf("Alarm arrived!\n");
    printf("%f\t%f\t\n", data.a, data.b);
    alarm(1);
}

int main(){

    struct two_double zeros={0.0, 0.0}, ones={1.0, 1.0};

    struct sigaction sa_alarm;
    sa_alarm.sa_handler = sigalarm_handler;
    sigemptyset(&sa_alarm.sa_mask);
    sigaction(SIGALRM, &sa_alarm, NULL);
    alarm(1);

    struct sigaction sa_int;
    sa_int.sa_handler = sigint_handler;
    sigemptyset(&sa_int.sa_mask);
    sa_int.sa_flags = 0;
    sigaction(SIGINT, &sa_int, NULL);
    
    struct sigaction sa_quit;
    sa_quit.sa_handler = sigquit_handler;
    sigemptyset(&sa_quit.sa_mask);
    sa_quit.sa_flags = 0;
    sigaction(SIGQUIT, &sa_quit, NULL);
    
    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGALRM);
    
    for(;;){
        //printf("pid : %lu\n", (unsigned long)getpid());
        //sleep(5); // 알람이 오면 sleep에서 깨어남! (5초로 설정해도 그냥 다시 alarm울릴 때 마다 실행함.)

        // Block SIGALRM
        sigprocmask(SIG_BLOCK, &mask, NULL);

        data = ones; // This is actually a combination of many commands (e.g., fetching memory values, storing, etc.)

        // Unblock SIGALRM
        sigprocmask(SIG_UNBLOCK, &mask, NULL);

        // Block SIGALRM
        sigprocmask(SIG_BLOCK, &mask, NULL);

        data = zeros;

        // Unblock SIGALRM
        sigprocmask(SIG_UNBLOCK, &mask, NULL);
        
    }
    return 0;
}