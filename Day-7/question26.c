//wap to recursive fibonacci.
#include<stdio.h>
int fib(int n)
{
    if(n==0 || n==1)//base case
    return n;
    else
    return fib(n-1)+fib(n-2);//recursive case   
}
int main()
{
    int num,f,i;
    printf("Enter the number of terms: ");
    scanf("%d",&num);
    printf("Fibbonacci series\n");
    for(i=0;i<num;i++)
    {
        f=fib(i);
        printf("%d ",f);
    }
    return 0;
}