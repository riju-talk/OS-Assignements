#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h> 

void delete_directory(const char *path) {
    struct dirent *entry;
    DIR *dir = opendir(path);

    if (dir == NULL) {
        perror("opendir");
        return;
    }
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char entry_path[1024];
        snprintf(entry_path, sizeof(entry_path), "%s/%s", path, entry->d_name);

        struct stat item_stat;
        stat(entry_path,&item_stat);
        if (S_ISDIR(item_stat.st_mode)) {
            delete_directory(entry_path);
        } else {
            if (remove(entry_path) != 0) {
                perror("remove");
            }
        }
    }
    closedir(dir);
    if (rmdir(path) != 0) {
        perror("rmdir");
    }
}

int main(int argc, char* argv[]){
    if(strcmp(argv[1],"-r")==0){
                
                char foldername[20];  
                strcpy(foldername,argv[2]);

                if (access(foldername, F_OK) != 0) {
                    printf("e: directory does not exist\n");
                    
                }
                else
                {
                    delete_directory(foldername);
                    mkdir(foldername,0777);
                    chdir(foldername);
                }
            }
    else if(strcmp(argv[1],"-v")==0){
                
                char foldername[20];  
                strcpy(foldername,argv[2]);

                if (access(foldername, F_OK) != 0) {
                    if(mkdir(foldername,0777)==0){
                    printf("making directory....\n");
                    sleep(2);
                    printf("directory made\n");
                    chdir(foldername);
                    }
                }
                else{
                    printf("e: directory exists\n");
                }
            }
    else{
            char foldername[20];  
            strcpy(foldername,argv[1]);
            if (access(foldername, F_OK) != 0) {
                mkdir(foldername,0777);
                chdir(foldername);
            }
            else{
                printf("e: directory exists\n");
            }
    }
    return 0;
}