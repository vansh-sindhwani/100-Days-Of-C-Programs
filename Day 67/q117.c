//Write a program to take two sorted arrays of size m and n as input. Merge both the arrays such that the merged array is also sorted. Print the merged array.
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int m, n;

    /* Read size and elements of the first sorted array */
    if (scanf("%d", &m) != 1 || m < 0)
        return 1;

    int *a = malloc((size_t)m * sizeof(int));
    if (m > 0 && a == NULL)
        return 1;

    for (int i = 0; i < m; i++) {
        if (scanf("%d", &a[i]) != 1) {
            free(a);
            return 1;
        }
    }

    /* Read size and elements of the second sorted array */
    if (scanf("%d", &n) != 1 || n < 0) {
        free(a);
        return 1;
    }

    int *b = malloc((size_t)n * sizeof(int));
    if (n > 0 && b == NULL) {
        free(a);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &b[i]) != 1) {
            free(a);
            free(b);
            return 1;
        }
    }

    int i = 0, j = 0;
    int first = 1;

    while (i < m && j < n) {
        int value;
        if (a[i] <= b[j])
            value = a[i++];
        else
            value = b[j++];

        if (!first) printf(" ");
        printf("%d", value);
        first = 0;
    }

    while (i < m) {
        if (!first) printf(" ");
        printf("%d", a[i++]);
        first = 0;
    }

    while (j < n) {
        if (!first) printf(" ");
        printf("%d", b[j++]);
        first = 0;
    }

    printf("\n");

    free(a);
    free(b);
    return 0;
}