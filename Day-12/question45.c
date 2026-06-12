//wap to write function for palindrome number.
#include <stdio.h>
int isPalindrome(int num) {
    int originalNum = num;
    int reversedNum = 0;

    while (num > 0) {
        int digit = num % 10; // Get the last digit
        reversedNum = reversedNum * 10 + digit; // Append the digit to the reversed number
        num /= 10; // Remove the last digit
    }

    return originalNum == reversedNum; // Check if the original number is equal to the reversed number
}
int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    if (isPalindrome(number)) {
        printf("%d is a palindrome number.\n", number);
    } else {
        printf("%d is not a palindrome number.\n", number);
    }
    return 0;
}