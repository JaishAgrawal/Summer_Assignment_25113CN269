//wap to write function for fibonacci series.
#include <stdio.h>
void fibonacci(int n) 
{
    int a = 0, b = 1, next;
    printf("Fibonacci series up to %d terms: ", n);
    for (int i = 0; i < n; i++)
    {
        if (i <= 1) 
        {
            next = i; // The first two terms are 0 and 1
        } else 
        {
            next = a + b; 
            a = b; 
            b = next; 
        }
        printf("%d ", next); // Print the current term
    }
    printf("\n");
}
int main()
 {
    int terms;
    printf("Enter the number of terms for Fibonacci series: ");
    scanf("%d", &terms);
    fibonacci(terms); // Call the function to print Fibonacci series
    return 0;
}