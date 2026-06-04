//wap to find nth term of fibonacci series.
#include<stdio.h>
int main()
{
    int n, first = 0, second = 1, next;
    
    printf("Enter the term number (n): ");
    scanf("%d", &n);
    
    if(n == 1) {
        printf("1st Fibonacci term = 0\n");
        return 0;
    }
    if(n == 2) {
        printf("2nd Fibonacci term = 1\n");
        return 0;
    }
    
    for(int i = 3; i <= n; i++) {
        next = first + second;
        first = second;
        second = next;
    }
    
    printf("%dth Fibonacci term = %d\n", n, second);
    return 0;
}