#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include "read.h"
#include "rd.h"
#include "rwn.h"

void splitString(char* input, char delimiter, char substrings[3][1000], int count) {
    char* token = strtok(input, &delimiter);
    int index = 0;

    while (token != NULL && index < count) {
        strcpy(substrings[index], token);
        (index)++;
        token = strtok(NULL, &delimiter);
    }
}

int main() {
    int cdir_count=0;
    char key[200];
    getcwd(key,200);
    char path[200];
    getcwd(path,200);
    strcat(key,"/mdir");
    while (true) {
        char set[5][1000];
        char sentence[1000];
        printf("[:--+++[%s]======:]>>==>> ",path);
        fgets(sentence, sizeof(sentence), stdin);
        sentence[strcspn(sentence, "\n")] = '\0';
        
        splitString(sentence,' ',set,5);
        
        if (strcmp(set[0], "word") == 0) {
            if(strcmp(set[1],"-n")==0){
                readwn(set[2]);
            }
            else if(strcmp(set[1],"-d")==0){
                readdiff(set[2],set[3]);   
            }            
            else{
                int res = readefile(set[1]);
                printf("%d\n",res);
            }
        } else if (strcmp(set[0], "dir") == 0) {
            char *args[]={key,set[1],set[2]};
            bool f_exists=false;
            if(strcmp("-r",set[1])==0 || strcmp("-v",set[1])==0 && (access(set[2],F_OK)==0)){
                    f_exists=true;
                }
                else if(access(set[1],F_OK)==0){ 
                    f_exists=true;
                }
            int k=fork();
            if(k==0){
                execv(key,args);
            }
            else{
                wait(NULL);
            }
                if((strcmp("-v",set[1])==0 )&& (access(set[2],F_OK)==0 && !f_exists)){
                    chdir(set[2]);
                    strcat(path,"/");
                    strcat(path,set[2]);
                }
                else if(access(set[1],F_OK)==0 && !f_exists){ 
                    chdir(set[1]);
                    strcat(path,"/");
                    strcat(path,set[1]);
                }
                else if(strcmp("-r",set[1])==0 && f_exists){
                    chdir(set[2]);
                    strcat(path,"/");
                    strcat(path,set[2]);
                }
        } else if (strcmp(set[0], "date") == 0) {
            char *args[]={"./time",set[1],set[2],set[3],NULL};
            int k=fork();
            if(k==0){ 
                execvp("./time",args);
            }
            else{
                wait(NULL);
            }
 
        } else if (strcmp(set[0], "exit()") == 0) {
            break;
        } else {
            printf("e: command not found\n");
        }
    }
    return 0;
}