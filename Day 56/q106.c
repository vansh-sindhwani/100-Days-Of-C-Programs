//Write a program to take an array arr[] of integers as input, the task is to find the next greater element for each element of the array in order of their appearance in the array. Next greater element of an element in the array is the nearest element on the right which is greater than the current element. If there does not exist next greater of current element, then next greater element for current element is -1.
#include <stdio.h>
#include <stdlib.h>

void nextGreaterElement(int arr[], int n, int res[]) {
    int *stack = malloc(n * sizeof(int));   /* stores values, not indices */
    int top = -1;                          /* empty stack */

    for (int i = n - 1; i >= 0; i--) {
        /* discard elements that can never be an answer for anything left of i */
        while (top >= 0 && stack[top] <= arr[i])
            top--;

        res[i] = (top < 0) ? -1 : stack[top];

        stack[++top] = arr[i];
    }

    free(stack);
}

int main(void) {
    int tests[][6] = {
        {4, 5, 2, 25, 0, 0},     /* n=4 */
        {13, 7, 6, 12, 0, 0},    /* n=4 */
        {11, 13, 21, 3, 0, 0},   /* n=4 */
    };
    int sizes[] = {4, 4, 4};

    for (int t = 0; t < 3; t++) {
        int n = sizes[t];
        int res[6];
        nextGreaterElement(tests[t], n, res);

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