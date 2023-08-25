#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>

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
        printf("[:--+++======>>>>> ");
        fgets(sentence, sizeof(sentence), stdin);

        // Remove the newline character from the input
        sentence[strcspn(sentence, "\n")] = '\0';
        
        splitString(sentence,' ',set,5);
        
        if (strcmp(set[0], "word") == 0) {            
            printf("Word\n");
        } else if (strcmp(set[0], "dir") == 0) {

            if(strcmp(set[1],"-r")==0){
                
                char foldername[20];  
                strcpy(foldername,set[2]);

                if (access(foldername, F_OK) == 0) {
                    rmdir(foldername);
                }

                mkdir(foldername,0777);

            }
            else if(strcmp(set[1],"-v")==0){
                
                char foldername[20];  
                strcpy(foldername,set[2]);

                if (access(foldername, F_OK) == 0) {
                    printf("e: directory exists\n");
                }

                if(mkdir(foldername,0777)==0){
                    printf("making directory....\n");
                    sleep(2);
                    printf("direcotry made\n");
                }
            }
            else{
                
                char foldername[20];  
                strcpy(foldername,set[1]);

                if (access(foldername, F_OK) == 0) {
                    printf("e: directory exists\n");
                }

                mkdir(foldername,0777);
            }


        } else if (strcmp(set[0], "date") == 0) {

            struct stat info;
            if(strcmp(set[1],"-d")==0){

                if (access(set[2],F_OK) == -1) {
                    printf("error: %s does not exist.\n",set[1]);
                    continue;
                }
                
                stat(set[2],&info);
                time_t mod_time = info.st_mtime;
                struct tm date = *localtime(&mod_time);
                printf("%d:%d:%d\n",date.tm_hour,date.tm_min,date.tm_sec);
            }
            else if(strcmp(set[1],"-R")==0){

                if (access(set[2],F_OK) == -1) {
                    printf("e: %s does not exist.\n",set[1]);
                    continue;
                }


                stat(set[2],&info);
                time_t mod_time = info.st_mtime;
                struct tm date = *localtime(&mod_time);
                char formattertime[200];
                strftime(formattertime,200,"%a, %d %h %Y %T %z",&date);
                printf("%s\n",formattertime);
            }
            else{

                if (access(set[1],F_OK) == -1) {
                    printf("e: %s does not exist.\n",set[1]);
                    continue;
                }

                stat(set[1],&info);
                time_t mod_time = info.st_mtime;
                struct tm date = *localtime(&mod_time);
                printf("%d/%d/%d %d:%d:%d\n",date.tm_mday,1+date.tm_mon,1900+date.tm_year,date.tm_hour,date.tm_min,date.tm_sec);
            
            }
 
        } else if (strcmp(set[0], "exit()") == 0) {
            break;
        } else {
            printf("e: command not found\n");
        }
    }
    return 0;
}
