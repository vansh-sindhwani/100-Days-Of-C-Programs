//A file numbers.txt contains a list of integers separated by spaces. Read all integers, compute their sum and average, and print both.
#include <stdio.h>

int main(void)
{
    FILE *fp;
    int value;
    int sum = 0;
    int count = 0;

    fp = fopen("numbers.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open numbers.txt for reading.\n");
        return 1;
    }

    while (fscanf(fp, "%d", &value) == 1) {
        sum += value;
        count++;
    }

    fclose(fp);

    if (count == 0) {
        printf("No integers found in numbers.txt\n");
        return 1;
    }

    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", (double)sum / count);

    return 0;
}