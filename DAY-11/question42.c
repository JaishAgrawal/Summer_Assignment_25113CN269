//wap to write function to find maximum.
#include <stdio.h>

int findMaximum(int a, int b) {
    if (a > b) {
        return a;          // Return a if it's greater than b
    } else {
        return b;          // Return b if it's greater than or equal to a
    }
}

int main() {
    int num1, num2;        // Declare two integers to hold user input
    
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);   // Read two integers from user input
    
    int max = findMaximum(num1, num2);  // Call the function to find the maximum
    
    // Print the result
    printf("The maximum of %d and %d is: %d\n", num1, num2, max);
    
    return 0;
}