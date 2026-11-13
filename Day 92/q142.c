//Store details of 5 students in an array of structures and print all.
#include <stdio.h>

#define NUM_STUDENTS 5

struct Student {
    char name[50];
    int roll_no;
    float marks;
};

int main(void)
{
    struct Student students[NUM_STUDENTS];
    int i;

    for (i = 0; i < NUM_STUDENTS; i++) {
        printf("\nStudent %d\n", i + 1);

        printf("Name: ");
        if (scanf("%49s", students[i].name) != 1) {
            printf("Invalid input.\n");
            return 1;
        }

        printf("Roll number: ");
        if (scanf("%d", &students[i].roll_no) != 1) {
            printf("Invalid input.\n");
            return 1;
        }

        printf("Marks: ");
        if (scanf("%f", &students[i].marks) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
    }

    printf("\n--- Student Records ---\n");
    printf("%-15s %-10s %-10s\n", "Name", "Roll No", "Marks");
    printf("-----------------------------------\n");

    for (i = 0; i < NUM_STUDENTS; i++) {
        printf("%-15s %-10d %-10.2f\n",
               students[i].name,
               students[i].roll_no,
               students[i].marks);
    }

    return 0;
}