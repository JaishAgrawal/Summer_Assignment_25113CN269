//wap to rotate array right by one position
#include<stdio.h>
int main()
{
    int a[100],n,i,temp;
    printf("Enter the size of array:");
    scanf("%d",&n);
    printf("Enter the elements of array:");
    for(i=0;i<n;i++)    {
        scanf("%d",&a[i]);
    }
    temp=a[n-1];
    for(i=n-1;i>0;i--)    {
        a[i]=a[i-1];    
    }
    a[0]=temp;
    printf("The rotated array is:");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}