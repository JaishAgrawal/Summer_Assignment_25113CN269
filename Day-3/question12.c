//Wap to find LCM of two numbers.
#include <stdio.h>
int main() {
    int num1, num2, lcm;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    // Find the greater of the two numbers
    int max = (num1 > num2) ? num1 : num2; //conditional operator to find the maximum of num1 and num2
    lcm = max; // Start with the greater number as the initial LCM
    while (1) 
    {
        if (lcm % num1 == 0 && lcm % num2 == 0)
         {
            break; // LCM found
        }
        lcm++; // Increment LCM by 1 and check again
    }
    printf("LCM of %d and %d is: %d\n", num1, num2, lcm);
    return 0;
}