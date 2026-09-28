//Change the date format from dd/04/yyyy to dd-Apr-yyyy.
#include <stdio.h>

int main() {
    char input[20];
    int day, month, year;

    // Month abbreviations (1-based)
    const char *months[] = {
        "", "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };

    printf("Enter date in dd/mm/yyyy format: ");
    scanf("%19s", input);

    // Parse the input
    if (sscanf(input, "%d/%d/%d", &day, &month, &year) != 3) {
        printf("Invalid date format!\n");
        return 1;
    }

    // Validate month
    if (month < 1 || month > 12) {
        printf("Invalid month!\n");
        return 1;
    }

    // Print in the new format
    printf("%02d-%s-%d\n", day, months[month], year);

    return 0;
}