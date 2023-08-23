#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    printf("Parent (P) is having ID %d\n",(int) getpid());
    int par_id=fork();

    if(par_id<0){
        printf("fork failes");
    }
    else if (par_id==0)
    {
        printf("Child is having ID %d\n",(int) getpid());
        printf("My Parent ID is %d\n",(int) getppid());
    }
    else{
        wait(NULL);
        printf("ID of P's Child is %d\n",(int) par_id);
    }
    
    return 0;
}
