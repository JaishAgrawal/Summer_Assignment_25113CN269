//wap to find missing number in array
#include<stdio.h>
int main()
{
    int a[100],n,i,sum=0,expected_sum;
    printf("Enter the size of array:");
    scanf("%d",&n);
    printf("Enter the elements of array:");
    for(i=0;i<n-1;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    expected_sum=n*(n+1)/2;
    printf("The missing number is:%d",expected_sum-sum);
    return 0;
}