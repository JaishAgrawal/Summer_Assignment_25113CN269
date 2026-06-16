//wap to find pair with gien sum.
#include<stdio.h>
int main()
{
    int a[100],n,i,j,sum;
    printf("Enter the size of array:");
    scanf("%d",&n);
    printf("Enter the elements of array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the sum:");
    scanf("%d",&sum);
    printf("The pairs with given sum are:\n");
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]+a[j]==sum)
            {
                printf("(%d,%d)\n",a[i],a[j]);
            }
        }
    }
    return 0;
}