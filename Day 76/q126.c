//Ask the user for a filename. Check if it exists by trying to open it in read mode. If the file pointer is NULL, print an error message; otherwise, read and display its content.
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char filename[256];
    FILE *fp;
    int ch;

    printf("Enter the filename to open: ");
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
        printf("The file may not exist or you may not have permission to read it.\n");
        return 1;
    }

    printf("\n--- Contents of \"%s\" ---\n", filename);
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    printf("\n--- End of file ---\n");

    fclose(fp);

    return 0;
}