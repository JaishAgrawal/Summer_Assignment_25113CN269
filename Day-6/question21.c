//wap to convert decimal to binary.
#include<stdio.h>
int main()
 {
    int num, binary[64], i = 0;
    printf("Enter a decimal number: ");
    scanf("%d", &num);
    while (num > 0) {
        binary[i] = num % 2; 
        num /= 2;
        i++;
    }
    printf("Binary representation: ");
    for (i = i - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
    return 0;
}