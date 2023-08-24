#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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
            printf("date\n");
        } else if (strcmp(set[0], "exit()") == 0) {
            break;
        } else {
            printf("%s\n", sentence);
        }
    }
    return 0;
}
