//Wap to reverse a number.
#include<stdio.h>
int main()
{    int n, reversed = 0, digit;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    
    while (n > 0) {
        digit = n % 10; // Get the last digit
        reversed = reversed * 10 + digit; // Append the digit to the reversed number
        n /= 10; // Remove the last digit
    }
    printf("The reversed number is: %d\n", reversed);
    return 0;
}