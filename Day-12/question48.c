//wap to write function to find the factorial of a number
#include <stdio.h>
int factorial(int num)
 {
    if (num < 0)
     {
        return -1; // Return -1 for negative numbers as factorial is not defined
    }
     else if (num == 0 || num == 1)
      {
        return 1; // Factorial of 0 and 1 is 1
    } 
    else
     {
        int result = 1; 
        for (int i = 2; i <= num; i++) 
        {
            result *= i; // Multiply result by each number from 2 to num
        }
        return result; // Return the factorial of num
    }
}
int main() {
    int number;
    printf("Enter a number to find its factorial: ");
    scanf("%d", &number);
    int result = factorial(number);
    if (result == -1) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        printf("Factorial of %d is %d.\n", number, result);
    }
    return 0;
}