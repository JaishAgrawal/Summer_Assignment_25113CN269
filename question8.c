//wap to check wheter a number is palindrome or not.
#include<stdio.h>
int main()
{    int n, reversed = 0, digit, original;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    original = n; // Store the original number for comparison
    while (n > 0) {
        digit = n % 10; // Get the last digit
        reversed = reversed * 10 + digit; // Append the digit to the reversed number
        n /= 10; // Remove the last digit
    }
    if (original == reversed) {
        printf("%d is a palindrome.\n", original);
    } else {
        printf("%d is not a palindrome.\n", original);
    }
    return 0;
}   