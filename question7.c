//wap to find product of a digits.
#include<stdio.h>
int main()
{    int n, product = 1, digit;
    printf("Enter a positive integer: ");
    scanf("%d", &n);   
    while (n > 0) {
        digit = n % 10; // Get the last digit
        product *= digit; // Multiply the digit to the product
        n /= 10; // Remove the last digit
    }
    printf("The product of the digits is: %d\n", product);
    return 0;
}