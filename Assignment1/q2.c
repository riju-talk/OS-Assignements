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
    char *dirs[100];
    while (true) {
        char set[5][1000];
        char sentence[1000];
        printf("[:--+++======:]>>==>> ");
        fgets(sentence, sizeof(sentence), stdin);

        // Remove the newline character from the input
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
            char *args[]={"./time",set[1],set[2],set[3]};
            int k=fork();
            if(k==0){
                execvp("./dir",args);
            }
            else{
                wait(NULL);
            }
        } else if (strcmp(set[0], "date") == 0) {
            char *args[]={"./time",set[1],set[2]};
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