//Print the initials of a name.
#include <stdio.h>

int main()
{
    char name[100];
    int i;

    printf("Enter your name: ");
    scanf(" %[^\n]", name);

    printf("Initials: %c", name[0]);

    for(i = 1; name[i] != '\0'; i++)
    {
        if(name[i] == ' ' && name[i + 1] != '\0')
        {
            printf("%c", name[i + 1]);
        }
    }

    return 0;
}