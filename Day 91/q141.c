//Define a structure Student with name, roll_no, and marks, then read and print one student's data.
#include <stdio.h>

struct Student {
    char name[50];
    int roll_no;
    float marks;
};

int main(void)
{
    struct Student s;

    printf("Enter name: ");
    if (scanf("%49s", s.name) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter roll number: ");
    if (scanf("%d", &s.roll_no) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter marks: ");
    if (scanf("%f", &s.marks) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("\n--- Student Details ---\n");
    printf("Name      : %s\n", s.name);
    printf("Roll No   : %d\n", s.roll_no);
    printf("Marks     : %.2f\n", s.marks);

    return 0;
}