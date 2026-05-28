//wap to count digits in a number
#include <stdio.h>
int main() {
    int num, count = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    while (num != 0) {
        num /= 10; // Remove the last digit
        count++;    // Increment the count of digits
    }
    printf("The number of digits in the given number is: %d\n", count);
    return 0;
}