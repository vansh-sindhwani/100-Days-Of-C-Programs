//Take two filenames from the user – a source file and a destination file. Copy all the content from the source file to the destination file using fgetc() and fputc().
#include <stdio.h>
#include <string.h>

int main(void) {
    char sourceName[256];
    char destinationName[256];

    printf("Enter source filename: ");
    if (scanf("%255s", sourceName) != 1)
        return 1;

    printf("Enter destination filename: ");
    if (scanf("%255s", destinationName) != 1)
        return 1;

    if (strcmp(sourceName, destinationName) == 0) {
        printf("Source and destination filenames must be different.\n");
        return 1;
    }

    FILE *source = fopen(sourceName, "r");
    if (source == NULL) {
        printf("Could not open source file.\n");
        return 1;
    }

    FILE *destination = fopen(destinationName, "w");
    if (destination == NULL) {
        printf("Could not open destination file.\n");
        fclose(source);
        return 1;
    }

    int ch;
    while ((ch = fgetc(source)) != EOF) {
        if (fputc(ch, destination) == EOF) {
            printf("Error copying file contents.\n");
            fclose(source);
            fclose(destination);
            return 1;
        }
    }

    if (ferror(source)) {
        printf("Error reading source file.\n");
        fclose(source);
        fclose(destination);
        return 1;
    }

    fclose(source);
    fclose(destination);

    printf("File copied successfully.\n");
    return 0;
}