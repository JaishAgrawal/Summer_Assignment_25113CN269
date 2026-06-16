//wap to remove duplicates from array
#include<stdio.h>
int main()
{
    int a[100],b[100],n,i,j,k=0,flag;
    printf("Enter the size of array:");
    scanf("%d",&n);
    printf("Enter the elements of array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        flag=0;
        for(j=0;j<k;j++)
        {
            if(a[i]==b[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            b[k++]=a[i];
        }
    }
    printf("The array after removing duplicates is:");
    for(i=0;i<k;i++)
    {
        printf("%d ",b[i]);
    }
    return 0;
}