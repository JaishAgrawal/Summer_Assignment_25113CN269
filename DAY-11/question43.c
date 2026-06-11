//wap to write function to check prime number.
#include <stdio.h>
int isPrime(int n) {
    if (n <= 1) {
        return 0; // Not prime
    }
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return 0; // Not prime
        }
    }
    return 1; // Prime
}
int main() {
    int num; // Declare an integer to hold user input
    printf("Enter a number: ");
    scanf("%d", &num); // Read an integer from user input
    
    if (isPrime(num)) {
        printf("%d is a prime number.\n", num); // Print if the number is prime
    } else {
        printf("%d is not a prime number.\n", num); // Print if the number is not prime
    }
    
    return 0;
}