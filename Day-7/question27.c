//wap to recursive sum of digits.
#include<stdio.h>
int sumOfDigits(int n) 
{
    if (n == 0) // Base case: if n is 0, return
        return 0;
    else
        return (n % 10) + sumOfDigits(n / 10); // Recursive case: add last digit to sum of remaining digits
}
int main() 
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int result = sumOfDigits(num);
    printf("Sum of digits of %d is: %d\n", num, result);
    return 0;
}
