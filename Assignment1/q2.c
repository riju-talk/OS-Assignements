#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int fib(int n){
    if(n<2){
        return n;
    }
    else{
        return fib(n-1)+(n-2);
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


int main(){
    printf("%d\n",fib(16));
    int child=fork();
    if(child<0){
        printf("Fork Failed\n");
    }
    else if(child==0){
        printf("%d\n",fac(4));
    }
    else{
        wait(NULL);
    }
    return 0;
}