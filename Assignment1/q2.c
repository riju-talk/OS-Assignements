#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>

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
    while (true) {
        char set[5][1000];
        char sentence[1000];
        printf("--+++======>>>>> ");
        fgets(sentence, sizeof(sentence), stdin);

        // Remove the newline character from the input
        sentence[strcspn(sentence, "\n")] = '\0';
        
        splitString(sentence,' ',set,5);
        
        if (strcmp(set[0], "word") == 0) {            
            printf("Word\n");
        } else if (strcmp(set[0], "dir") == 0) {
            printf("dir\n");
        } else if (strcmp(set[0], "date") == 0) {
            struct stat info;
            if(strcmp(set[1],"-d")==0){
                stat(set[2],&info);
                time_t mod_time = info.st_mtime;
                struct tm date = *localtime(&mod_time);
                printf("%d:%d:%d\n",date.tm_hour,date.tm_min,date.tm_sec);
            }
            else if(strcmp(set[1],"-R")==0){
                stat(set[2],&info);
                time_t mod_time = info.st_mtime;
                struct tm date = *localtime(&mod_time);
                char formattertime[200];
                strftime(formattertime,200,"%a, %d %h %Y %T %z",&date);
                printf("%s\n",formattertime);
            }
            else{
                stat(set[1],&info);
                time_t mod_time = info.st_mtime;
                struct tm date = *localtime(&mod_time);
                printf("%d/%d/%d %d:%d:%d\n",date.tm_mday,1+date.tm_mon,1900+date.tm_year,date.tm_hour,date.tm_min,date.tm_sec);
            }
 
        } else if (strcmp(set[0], "exit()") == 0) {
            break;
        } else {
            printf("%s\n", sentence);
        }
    }
    return 0;
}
