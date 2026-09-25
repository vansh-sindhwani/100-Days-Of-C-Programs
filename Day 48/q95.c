//Check if one string is a rotation of another.
#include <stdio.h>
#include <string.h>

int main()
{
    char a[100], b[100], temp[200];

    printf("Enter first string: ");
    scanf("%99s", a);

    printf("Enter second string: ");
    scanf("%99s", b);

    if(strlen(a) != strlen(b))
    {
        printf("Not a rotation");
        return 0;
    }

    strcpy(temp, a);
    strcat(temp, a);

    if(strstr(temp, b))
        printf("It is a rotation");
    else
        printf("Not a rotation");

    return 0;
}