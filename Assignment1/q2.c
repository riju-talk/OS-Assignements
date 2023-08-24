#include<stdio.h>
#include<time.h>
#include<stdbool.h>
#include<string.h>

int main(){
    while (true)
    {
        char k[12];
        char l[12];
        char m[12];
        printf(":::-----+++======>>>>> ");
        scanf("%s %s %s",k,l,m);
        if(strcmp(k,"word")==0){
            printf("word\n");
        }
        else if(strcmp(k,"dir")==0){
            printf("dir\n");
        }
        else if(strcmp(k,"date")==0){
            printf("date\n");
        }
        else if(strcmp(k,"exit()")==0){
            break;
        }
    }
    return 0;
}
