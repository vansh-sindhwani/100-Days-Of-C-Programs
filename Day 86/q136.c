//Use enum to represent menu choices (ADD, SUBTRACT, MULTIPLY) and perform operations using switch.
#include <stdio.h>

enum MenuChoice {
    ADD,
    SUBTRACT,
    MULTIPLY
};

int main(void)
{
    enum MenuChoice choice;
    double a, b, result;

    printf("Menu:\n");
    printf("0 - ADD\n");
    printf("1 - SUBTRACT\n");
    printf("2 - MULTIPLY\n");
    printf("Enter choice: ");
    if (scanf("%d", (int *)&choice) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter two numbers: ");
    if (scanf("%lf %lf", &a, &b) != 2) {
        printf("Invalid input.\n");
        return 1;
    }

    switch (choice) {
        case ADD:
            result = a + b;
            printf("%.2f + %.2f = %.2f\n", a, b, result);
            break;
        case SUBTRACT:
            result = a - b;
            printf("%.2f - %.2f = %.2f\n", a, b, result);
            break;
        case MULTIPLY:
            result = a * b;
            printf("%.2f * %.2f = %.2f\n", a, b, result);
            break;
        default:
            printf("Invalid menu choice.\n");
            return 1;
    }

    return 0;
}