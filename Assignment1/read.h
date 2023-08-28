#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>

bool isDelimiter(char ch) {
    return (ch == ' ' || ch == '\n' || ispunct(ch));
}

int readefile(char* args) {
    FILE *file;
    char ch;
    int wordCount = 0;
    bool inWord = false;
    file = fopen(args, "r");

    if (file == NULL) {
        printf("e: File not found!\n");
        return 1;
    }


    while ((ch = fgetc(file)) != EOF) {
        if (!isDelimiter(ch)) {
            // We are in a word
            if (!inWord) {
                inWord = true;
                wordCount++;
            }
        } else {

            inWord = false;
        }
    }

    fclose(file);

    return wordCount;
}
