//Write a program to take an array arr[] of integers as input, the task is to find the previous greater element for each element of the array in order of their appearance in the array. Previous greater element of an element in the array is the nearest element on the left which is greater than the current element. If there does not exist next greater of current element, then previous greater element for current element is -1.
#include <stdio.h>
#include <stdlib.h>

void prevGreaterElement(int arr[], int n, int res[]) {
    int *stack = malloc(n * sizeof(int));
    int top = -1;

    for (int i = 0; i < n; i++) {
        while (top >= 0 && stack[top] <= arr[i])
            top--;

        res[i] = (top < 0) ? -1 : stack[top];
        stack[++top] = arr[i];
    }

    free(stack);
}

int main(void) {
    int tests[][6] = {
        {4, 5, 2, 25, 0, 0},
        {13, 7, 6, 12, 0, 0},
        {11, 13, 21, 3, 0, 0},
    };
    int sizes[] = {4, 4, 4};

    for (int t = 0; t < 3; t++) {
        int n = sizes[t];
        int res[6];
        prevGreaterElement(tests[t], n, res);

        printf("Input:  [");
        for (int i = 0; i < n; i++)
            printf("%d%s", tests[t][i], i == n - 1 ? "" : ", ");
        printf("]\nOutput: [");
        for (int i = 0; i < n; i++)
            printf("%d%s", res[i], i == n - 1 ? "" : ", ");
        printf("]\n\n");
    }
    return 0;
}