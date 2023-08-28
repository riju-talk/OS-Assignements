#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
        struct stat info;
            if(strcmp(argv[1],"-d")==0){

                if (access(argv[2],F_OK) == -1) {
                    printf("error: %s does not exist.\n",argv[1]);
                    exit(1);
                }
                
                stat(argv[2],&info);
                time_t mod_time = info.st_mtime;
                struct tm date = *localtime(&mod_time);
                printf("%d:%d:%d\n",date.tm_hour,date.tm_min,date.tm_sec);
            }
            else if(strcmp(argv[1],"-R")==0){

                if (access(argv[2],F_OK) == -1) {
                    printf("e: %s does not exist.\n",argv[1]);
                    exit(1);
                }


                stat(argv[2],&info);
                time_t mod_time = info.st_mtime;
                struct tm date = *localtime(&mod_time);
                char formattertime[200];
                strftime(formattertime,200,"%a, %d %h %Y %T %z",&date);
                printf("%s\n",formattertime);
            }
            else{

                if (access(argv[1],F_OK) == -1) {
                    printf("e: %s does not exist.\n",argv[1]);
                    exit(1);
                }

                stat(argv[1],&info);
                time_t mod_time = info.st_mtime;
                struct tm date = *localtime(&mod_time);
                printf("%d/%d/%d %d:%d:%d\n",date.tm_mday,1+date.tm_mon,1900+date.tm_year,date.tm_hour,date.tm_min,date.tm_sec);
            }
    return 0;
}