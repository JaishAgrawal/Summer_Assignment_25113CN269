//wap to recursive factorial.
#include<stdio.h>
int fact(int n)
{
    if(n==0 || n==1)//base case
    return 1;
    else
    return n*fact(n-1);//recursive case 
}
int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    printf("Factorial of %d is: %d\n",n,fact(n));
    return 0;
}