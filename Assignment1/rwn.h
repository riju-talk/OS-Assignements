#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>


bool isDelimit(char ch) {
    return (ch == ' ' || ch == '\n' || ispunct(ch));
}

int readwn(char* args) {
    FILE *file;
    char ch;
    int wordCount = 0;
    int newlineCount = 0; 
    bool inWord = false;


    file = fopen(args, "r");


    if (file == NULL) {
        printf("e: File not found!\n");
        return 1;
    }


    while ((ch = fgetc(file)) != EOF) {
        if (!isDelimit(ch)) {
            // We are in a word
            if (!inWord) {
                inWord = true;
                wordCount++;
            }
        } else {
 
            inWord = false;


            if (ch == '\n') {
                newlineCount++;
            }
        }
    }


    fclose(file);

    printf("%d\n", wordCount-newlineCount);
    return 0;
}
