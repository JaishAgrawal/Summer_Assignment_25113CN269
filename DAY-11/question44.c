//wap to write function to find factorial of a number.
#include <stdio.h>

int factorial(int n) {
    if (n < 0) {
        return -1;         // Return -1 for negative numbers
    }
    
    int fact = 1;          // Initialize factorial to 1
    for (int i = 1; i <= n; i++) {
        fact *= i;         // Multiply fact by current number
    }
    return fact;           // Return the final factorial value
}

int main() {
    int num;               // Declare an integer to hold user input
    
    printf("Enter a number: ");
    scanf("%d", &num);     // Read an integer from user input
    
    int result = factorial(num);   // Call the function to calculate factorial
    
    if (result == -1) {
        printf("Factorial is not defined for negative numbers.\n"); // Handle negative input
    } else {
        printf("The factorial of %d is: %d\n", num, result);       // Print the result
    }
    
    return 0;
}