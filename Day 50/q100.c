//Print all sub-strings of a string.
#include <stdio.h>
#include <string.h>

int main() {
    // Change this string as you like
    char str[] = "abc";

    int len = strlen(str);
    int i, j, k;

    printf("All substrings of \"%s\" are:\n\n", str);

    for (i = 0; i < len; i++) {          // starting index
        for (j = i; j < len; j++) {       // ending index
            for (k = i; k <= j; k++) {
                putchar(str[k]);
            }
            putchar('\n');
        }
    }

    return 0;
}