//wap to print prime numbers in a given range
#include <stdio.h>
int main()
{ 
    
    int lower, upper, i, j, isPrime;
    printf("Enter lower and upper limits: ");
    scanf("%d %d", &lower, &upper); 
    printf("Prime numbers between %d and %d are: ", lower, upper); 
    for (i = lower; i <= upper; i++) 
    {
        if (i <= 1) 
        {
            continue; // skip numbers less than or equal to 1
        }
        isPrime = 1; // assume number is prime
        for (j = 2; j <= i / 2; j++) 
        {
            if (i % j == 0) 
            {
                isPrime = 0; // number is divisible by another number
                break;
            }
        }
        if (isPrime) 
        {
            printf("%d ", i); // print the prime number
        }
    }
    printf("\n");
    return 0;
}