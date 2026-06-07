//wap to recursive reverse of a number.
#include<stdio.h>
int reverse(int n, int rev)
{
    if(n==0) // Base case: if n is 0, return the reversednumber
        return rev;
    else
        return reverse(n / 10, rev * 10 + n % 10); // Recursive case: add last digit to rev and call reverse with remaining digits
}
int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);  
    int result = reverse(num, 0); // Start with rev as 0
    printf("Reverse of %d is: %d\n", num, result);
    return 0;
}