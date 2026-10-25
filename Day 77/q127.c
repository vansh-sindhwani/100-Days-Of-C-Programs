//Write a program that reads text from input.txt, converts all lowercase letters to uppercase, and writes the result to output.txt.
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    FILE *in = fopen("input.txt", "r");
    if (in == NULL) {
        printf("Error: Could not open input.txt for reading.\n");
        return 1;
    }

    FILE *out = fopen("output.txt", "w");
    if (out == NULL) {
        printf("Error: Could not open output.txt for writing.\n");
        fclose(in);
        return 1;
    }

    int ch;
    while ((ch = fgetc(in)) != EOF) {
        fputc(toupper((unsigned char)ch), out);
    }

    fclose(in);
    fclose(out);

    printf("Conversion complete. Result written to output.txt\n");
    return 0;
}