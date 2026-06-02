//wap to find product of digits of a number 
#include <stdio.h>

int main() {
    int num, product = 1;
    printf("Enter a number: ");
    scanf("%d", &num);

    while (num > 0) {
        product *= num % 10; // multiply the last digit to product
        num /= 10; // remove the last digit
    }

    printf("Product of digits: %d\n", product);
    return 0;
}