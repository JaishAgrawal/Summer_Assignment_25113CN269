//wap to find reverse a number
#include <stdio.h>

int main() {
    int num, reverse = 0, remainder;

    // Ask user for input
    printf("Enter an integer: ");
    scanf("%d", &num);

    // Loop to reverse the digits
    while (num != 0) {
        remainder = num % 10;         // Get the last digit
        reverse = reverse * 10 + remainder; // Append digit to reversed number
        num /= 10;                    // Remove the last digit
    }

    // Output the result
    printf("Reversed number = %d\n", reverse);

    return 0;
}
