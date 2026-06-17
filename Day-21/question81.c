//wap to find string length without strlen().
#include <stdio.h>

int main() {
    char str[100];
    int length = 0;

    // Get string input from the user
    printf("Enter a string: ");
    // Using fgets to safely allow spaces in the input string
    fgets(str, sizeof(str), stdin);

    // Loop until the null terminator is reached
    while (str[length] != '\0') {
        length++;
    }

    // Remove the newline character if it was captured by fgets
    if (length > 0 && str[length - 1] == '\n') {
        length--;
    }

    // Print the calculated length
    printf("Length of the string: %d\n", length);

    return 0;
}
