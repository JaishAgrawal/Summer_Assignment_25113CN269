//wap to find factorial of a given number.
#include<stdio.h>
int main()
{
    int n,fact=1;
    printf("Enter a number: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        fact*=i; //fact=fact*i  (assignment operator)
    }
    printf("Factorial of %d is: %d", n, fact);
    return 0;
}