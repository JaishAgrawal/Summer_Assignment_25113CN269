//wap to check strong number.
#include<stdio.h>
int main()
{
    int num, sum = 0, original, remainder, factorial;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    original = num;
    
    while(original != 0)
     {
        remainder = original % 10;
        factorial = 1;
        
        for(int i = 1; i <= remainder; i++) 
        {
            factorial *= i;
        }
        
        sum += factorial;
        original /= 10;
    }
    
    if(sum == num) 
    {
        printf("%d is a strong number.\n", num);
    } 
    else 
    {
        printf("%d is not a strong number.\n", num);
    }
    
    return 0;
}