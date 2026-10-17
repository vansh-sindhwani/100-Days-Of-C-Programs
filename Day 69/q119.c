//Write a program to take an integer array as input. Only one element will be repeated. Print the repeated element. Try to find the result in one single iteration.
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;

    if (scanf("%d", &n) != 1 || n <= 0)
        return 1;

    size_t capacity = (size_t)n * 2 + 1;
    int *table = malloc(capacity * sizeof(int));
    char *used = calloc(capacity, sizeof(char));

    if (table == NULL || used == NULL) {
        free(table);
        free(used);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        int value;
        if (scanf("%d", &value) != 1) {
            free(table);
            free(used);
            return 1;
        }

        size_t index =
            ((unsigned long long)(unsigned int)value * 2654435761ULL) % capacity;

        while (used[index]) {
            if (table[index] == value) {
                printf("%d\n", value);
                free(table);
                free(used);
                return 0;
            }
            index = (index + 1) % capacity;
        }

        table[index] = value;
        used[index] = 1;
    }

    printf("-1\n");
    free(table);
    free(used);
    return 0;
}