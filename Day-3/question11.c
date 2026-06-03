//wap to find GCD of two numbers.  
#include <stdio.h>
int main() {
    int num1, num2, gcd;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Find the smaller of the two numbers
    int min = (num1 < num2) ? num1 : num2;//conditional operator to find the minimum of num1 and num2

    // Loop from 1 to min to find the GCD
    for (int i = 1; i <= min; i++)
     {
        if (num1 % i == 0 && num2 % i == 0) 
        {
            gcd = i; // Update GCD if both numbers are divisible by i
        }
    }

    printf("GCD of %d and %d is: %d\n", num1, num2, gcd);
    return 0;
}