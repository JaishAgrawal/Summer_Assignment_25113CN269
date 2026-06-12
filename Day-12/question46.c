//wap to write function for armstrong number.
#include <stdio.h>
int isArmstrong(int num)
 {
    int originalNum = num;
    int sum = 0;
    int n = 0;
    while (originalNum > 0)
     {
        originalNum /= 10;
        n++;
    }
    originalNum = num; // Reset originalNum to the input number
    // Calculate the sum of the cubes of the digits
    while (originalNum > 0) 
    {
        int digit = originalNum % 10; // Get the last digit
        sum += digit * digit * digit; // Add the cube of the digit to the sum
        originalNum /= 10; // Remove the last digit
    }
    return sum == num; // Check if the sum of the cubes of the digits is equal to the original number
}
int main()
 {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    if (isArmstrong(number)) {
        printf("%d is an Armstrong number.\n", number);
    } else {        printf("%d is not an Armstrong number.\n", number);
    }   return 0;  
 }