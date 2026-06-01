//Wap to find dum of a digits of a number.
#include<stdio.h>
int main()
{
    int n, sum = 0, digit;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    
    while (n > 0) {
        digit = n % 10; // Get the last digit
        sum += digit;   // Add the digit to the sum
        n /= 10;        // Remove the last digit
    }
    
    printf("The sum of the digits is: %d\n", sum);
    
    return 0;
}