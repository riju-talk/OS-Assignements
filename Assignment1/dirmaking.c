#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char* argv[]){
    if(strcmp(argv[1],"-r")==0){
                
                char foldername[20];  
                strcpy(foldername,argv[2]);

                if (access(foldername, F_OK) == 0) {
                    rmdir(foldername);
                }

                mkdir(foldername,0777);
                chdir(foldername);
            }
    else if(strcmp(argv[1],"-v")==0){
                
                char foldername[20];  
                strcpy(foldername,argv[2]);

                if (access(foldername, F_OK) == 0) {
                    printf("e: directory exists\n");
                }

                if(mkdir(foldername,0777)==0){
                    printf("making directory....\n");
                    sleep(2);
                    printf("direcotry made\n");
                    chdir(foldername);
                }
            }
    else{
                
                char foldername[20];  
                strcpy(foldername,argv[1]);

                if (access(foldername, F_OK) == 0) {
                    printf("e: directory exists\n");
                }

                mkdir(foldername,0777);
                chdir(foldername);
            }
    return 0;
}