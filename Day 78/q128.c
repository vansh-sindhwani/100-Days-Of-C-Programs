//Read a text file and count how many vowels and consonants are in the file. Ignore digits and special characters
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>

int main(void)
{
    char filename[256];
    FILE *fp;
    int ch;
    int vowels = 0, consonants = 0;

    printf("Enter the filename: ");
    if (fgets(filename, sizeof(filename), stdin) == NULL) {
        fprintf(stderr, "Error reading filename.\n");
        return 1;
    }

    size_t len = 0;
    while (filename[len] != '\0') {
        if (filename[len] == '\n') {
            filename[len] = '\0';
            break;
        }
        len++;
    }

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file \"%s\".\n", filename);
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        if (isalpha((unsigned char)ch)) {
            switch (tolower((unsigned char)ch)) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    vowels++;
                    break;
                default:
                    consonants++;
                    break;
            }
        }
    }

    fclose(fp);

    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);

    return 0;
}