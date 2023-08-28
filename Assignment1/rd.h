#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>
#include <math.h>  
#include <stdlib.h>

bool isDelimiting(char ch) {
    return (ch == ' ' || ch == '\n' || ispunct(ch));
}

int readdiff(char* f1,char* f2) {
    FILE *file1;
    FILE *file2;
    char ch;
    int wordCount1 = 0;
    int wordCount2 = 0;
    bool inWord1 = false;
    bool inWord2 = false;
    file1 = fopen(f1, "r");
    file2 = fopen(f2, "r");

    if (file1 == NULL) {
        printf("e: File not found!\n");
        return 1;
    }

    // Count words
    while ((ch = fgetc(file1)) != EOF) {
        if (!isDelimiting(ch)) {
            if (!inWord1) {
                inWord1 = true;
                wordCount1++;
            }
        } else {
            inWord1 = false;
        }
    }

    if (file2 == NULL) {
        printf("e: File not found!\n");
        return 1;
    }

    while ((ch = fgetc(file2)) != EOF) {
        if (!isDelimiting(ch)) {
            if (!inWord2) {
                inWord2 = true;
                wordCount2++;
            }
        } else {
            inWord2 = false;
        }
    }

    fclose(file1);
    fclose(file2);
    int vale = wordCount1 - wordCount2;
    printf("%d\n", abs(vale));

    return 0;
}
