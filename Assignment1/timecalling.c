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

                if (access(argv[3],F_OK) == -1) {
                    printf("e: file does not exist.\n");
                    exit(1);
                }
                //MON Aug 25 01:15:50 PM IT 2023
                stat(argv[3],&info);
                time_t mod_time = info.st_mtime;
                struct tm date = *localtime(&mod_time);
                if(strcmp(argv[2],"'yesterday'")==0){
                    date.tm_mday=date.tm_mday-1;
                    if (date.tm_mday <= 0) {
                        date.tm_mon--; 
                        if (date.tm_mon < 0) {
                            date.tm_mon = 11;  
                            date.tm_year--;    
                        }
                        int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
                        date.tm_mon = daysInMonth[date.tm_mon];
                    }
                    char formattertime[200];
                    strftime(formattertime,200,"%a %b %d %I:%M:%S %p %Z %Y",&date);
                    printf("%s\n",formattertime);
                }
                else if(strcmp(argv[2],"'tomorrow'")==0){
                    date.tm_mday=date.tm_mday+1;
                    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
                    if (date.tm_mday > daysInMonth[date.tm_mon]) {
                        date.tm_mday = 1;
                        date.tm_mon++;

                        if (date.tm_mon > 11) {
                            date.tm_mon = 0;
                            date.tm_year++;
                        }
                    }
                    char formattertime[200];
                    strftime(formattertime,200,"%a %b %d %I:%M:%S %p %Z %Y",&date);
                    printf("%s\n",formattertime);
                }
                else if(strcmp(argv[2],"'now'")==0){
                    char formattertime[200];
                    strftime(formattertime,200,"%a %b %d %I:%M:%S %p %Z %Y",&date);
                    printf("%s\n",formattertime);
                }
                else{
                    printf("e: incorrect set of arguments\n");
                }
            }
            else if(strcmp(argv[1],"-R")==0){

                if (access(argv[2],F_OK) == -1) {
                    printf("e: %s does not exist.\n",argv[2]);
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
                char formattertime[200];
                strftime(formattertime,200,"%a %b %d %I:%M:%S %p %Z %Y",&date);
                printf("%s\n",formattertime);
            }
    return 0;
}