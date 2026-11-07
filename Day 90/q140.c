//Define a struct with enum Gender and print person's gender.
#include <stdio.h>

enum Gender {
    MALE,
    FEMALE,
    OTHER
};

struct Person {
    char name[50];
    int age;
    enum Gender gender;
};

int main(void)
{
    struct Person p = { "Alice", 30, FEMALE };

    const char *genderNames[] = { "MALE", "FEMALE", "OTHER" };

    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Gender: %s\n", genderNames[p.gender]);

    return 0;
}