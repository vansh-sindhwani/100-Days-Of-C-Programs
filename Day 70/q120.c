//Write a program to take a string input. Change it to sentence case.
#include <stdio.h>
#include <ctype.h>

int main(void) {
    char str[1000];

    if (fgets(str, sizeof(str), stdin) == NULL)
        return 1;

    int sentenceStart = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)str[i];

        if (isalpha(ch)) {
            str[i] = sentenceStart ? (char)toupper(ch) : (char)tolower(ch);
            sentenceStart = 0;
        } else if (ch == '.' || ch == '?' || ch == '!' || ch == '\n') {
            sentenceStart = 1;
        }
    }

    printf("%s", str);
    return 0;
}