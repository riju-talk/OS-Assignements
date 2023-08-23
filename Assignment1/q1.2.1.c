#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int fib(int n){
    if(n<2){
        return n;
    }
    else{
        return fib(n-1)+fib(n-2);
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

    int child=vfork();
    
    if(child<0){
        printf("Fork Failed\n");
    }
    else if(child==0){
        printf("%d\n",fac(4));
    }
    else{
        wait(NULL);
        printf("%d\n",fib(16));
    }
    return 0;
}