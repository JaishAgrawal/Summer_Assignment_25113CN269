//wap to find x^n without pow function.
#include<stdio.h>
int main() {
    double x, result = 1.0;
    int n, i;
    printf("Enter a number (x): ");
    scanf("%lf", &x);
    printf("Enter an exponent (n): ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        result *= x; // Multiply result by x in each iteration
    }
    printf("%.2lf raised to the power of %d is: %.2lf\n",
              x, n, result);
    return 0;
}