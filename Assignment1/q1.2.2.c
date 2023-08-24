#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int fib_n(int n){
    if(n<2){
        return n;
    }
    else{
        return fib_n(n-1)+fib_n(n-2);
    }
}

int fib(int n){
    for(int i=1;i<=n;i++){
        printf("%d,",fib_n(i));
    }
}

int fac(int n){
    if(n<2){
        return 1;
    }
    else{
        return n*fac(n-1);
    }
}

int main() {
    __pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0) {
        sleep(3);
        printf("%d\n",fac(4));
    } 
    else {
        kill(pid,SIGSTOP);
        fib(16);
        kill(pid,SIGCONT);
        wait(NULL);
    }
    return 0;
}
