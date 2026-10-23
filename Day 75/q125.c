//Open an existing file in append mode and allow the user to enter a new line of text. Append the text at the end without overwriting existing content.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char line[1000];

    FILE *file = fopen("info.txt", "a");
    if (file == NULL) {
        printf("Could not open info.txt\n");
        return 1;
    }

    printf("Enter a line to append: ");
    if (fgets(line, sizeof(line), stdin) == NULL) {
        fclose(file);
        return 1;
    }

    if (fputs(line, file) == EOF) {
        printf("Could not write to file.\n");
        fclose(file);
        return 1;
    }

    if (strchr(line, '\n') == NULL)
        fputc('\n', file);

    fclose(file);
    printf("Text appended successfully.\n");

    return 0;
}