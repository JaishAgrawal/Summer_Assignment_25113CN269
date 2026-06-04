//wap to check armstrong number.
#include<stdio.h>
int main()
{
    int num,original,remainder,result=0,n=0,pow;
    printf("Enter a number:");
    scanf("%d",&num);

    original=num;
    while(original!=0)
    {
        original/=10;//assignment operator
        n++;    
    }
    original=num;
    while(original!=0)
        {
        remainder=original%10;
        pow=1;
        for(int i=0;i<n;i++)
        {
            pow*=remainder;
        }
        result+=pow;
        original/=10; 
        }
    if(result==num)
        printf("%d is an Armstrong number.\n", num);
    else
        printf("%d is not an Armstrong number.\n", num);
    return 0;
}