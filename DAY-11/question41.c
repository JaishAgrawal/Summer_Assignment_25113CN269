//wap tp write function to find sum of tum numbers from 1 to n.
#include <stdio.h>

int sumOfNumbers(int n) {
    int sum = 0;           // Start with sum = 0
    for (int i = 1; i <= n; i++) {
        sum += i;          // Add current number to sum
    }
    return sum;            // Return the final sum
}

int main() {
    int n;                     // Number of terms to sum
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    int result = sumOfNumbers(n);  // Call the function
    
    // Print the result
    printf("The sum of numbers from 1 to %d is: %d\n", n, result);
    
    return 0;
}