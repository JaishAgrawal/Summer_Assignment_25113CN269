//wap to find largest prime factor.
#include<stdio.h>
#include<math.h>
int main() {
    int num, i, largest = -1;
    printf("Enter a number: ");
    scanf("%d", &num);
    // Check for number of 2s that divide num
    while (num % 2 == 0) {
        largest = 2;
        num /= 2;
    }
    // num must be odd at this point, so we can skip even numbers
    for (i = 3; i <= sqrt(num); i += 2) {
        while (num % i == 0) {
            largest = i;
            num /= i;   
        }
    }
    // This condition is to check if num is a prime number greater than 2
    if (num > 2) {
        largest = num;
    }
    printf("The largest prime factor is: %d\n", largest);
    return 0;
}