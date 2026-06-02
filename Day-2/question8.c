//wap to check whether a number is palindrome or not
#include <stdio.h>

int main() {
    int num, originalNum, reverse = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    originalNum = num;

    while (num > 0) {
        reverse = reverse * 10 + num % 10;
        num /= 10;
    }

    if (originalNum == reverse) {
        printf("%d is a palindrome.\n", originalNum);
    } else {
        printf("%d is not a palindrome.\n", originalNum);
    }

    return 0;
}