//Write a C program that creates a text file named info.txt in write mode. The program should take the user’s name and age as input, and write them to the file using fprintf(). After writing, display a message confirming that the data was successfully saved.
#include <stdio.h>
#include <string.h>

int main(void) {
    char name[100];
    int age;

    if (fgets(name, sizeof(name), stdin) == NULL)
        return 1;
    name[strcspn(name, "\n")] = '\0';

    if (scanf("%d", &age) != 1)
        return 1;

    FILE *file = fopen("info.txt", "w");
    if (file == NULL)
        return 1;

    fprintf(file, "%s\n%d\n", name, age);
    fclose(file);

    printf("Data saved successfully.\n");
    return 0;
}
