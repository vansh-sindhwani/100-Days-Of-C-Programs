//Store multiple student records (name, roll number, marks) into a file using fprintf(). Then read them using fscanf() and display each record.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME 50
#define NUM_STUDENTS 3

int main(void)
{
    FILE *fp = NULL;
    int i;
    char name[MAX_NAME] = {0};
    int roll = 0;
    float marks = 0.0f;

    fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf("Error: Could not open students.txt for writing.\n");
        return 1;
    }

    printf("Enter details for %d students:\n", NUM_STUDENTS);
    for (i = 0; i < NUM_STUDENTS; i++) {
        printf("\nStudent %d\n", i + 1);

        printf("Name: ");
        scanf("%49s", name);

        printf("Roll number: ");
        scanf("%d", &roll);

        printf("Marks: ");
        scanf("%f", &marks);

        fprintf(fp, "%s %d %.2f\n", name, roll, marks);
    }

    fclose(fp);

    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open students.txt for reading.\n");
        return 1;
    }

    printf("\n--- Student Records ---\n");
    printf("%-15s %-10s %-10s\n", "Name", "Roll No", "Marks");
    printf("-----------------------------------\n");

    while (fscanf(fp, "%49s %d %f", name, &roll, &marks) == 3) {
        printf("%-15s %-10d %-10.2f\n", name, roll, marks);
    }

    fclose(fp);

    return 0;
}