//Read a text file and count the total number of characters, words, and lines. A word is defined as a sequence of non-space characters separated by spaces or newlines.
#include <stdio.h>
#include <ctype.h>

#ifndef EOF
#define EOF (-1)
#endif

int main(void) {
    FILE *file = fopen("info.txt", "r");
    if (file == NULL) {
        printf("Could not open info.txt\n");
        return 1;
    }

    int ch;
    int inWord = 0;
    int lastChar = '\n';
    long long characters = 0;
    long long words = 0;
    long long lines = 0;

    while ((ch = fgetc(file)) != EOF) {
        characters++;
        lastChar = ch;

        if (ch == '\n')
            lines++;

        if (isspace((unsigned char)ch)) {
            inWord = 0;
        } else if (!inWord) {
            words++;
            inWord = 1;
        }
    }

    if (characters > 0 && lastChar != '\n')
        lines++;

    fclose(file);

    printf("Characters: %lld\n", characters);
    printf("Words: %lld\n", words);
    printf("Lines: %lld\n", lines);

    return 0;
}