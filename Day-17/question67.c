//wap to intersection of two arrays.
#include<stdio.h>
int main()  
{
    int a[100],b[100],c[100],n1,n2,i,j,k=0;
    printf("Enter the size of first array:");
    scanf("%d",&n1);
    printf("Enter the elements of first array:");
    for(i=0;i<n1;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the size of second array:");
    scanf("%d",&n2);
    printf("Enter the elements of second array:");
    for(i=0;i<n2;i++)
    {
        scanf("%d",&b[i]);
    }
    for(i=0;i<n1;i++)
    {
        for(j=0;j<n2;j++)
        {
            if(a[i]==b[j])
            {
                c[k++]=a[i];
                break;
            }
        }
    }
    printf("The intersection of two arrays is:");
    for(i=0;i<k;i++)
    {
        printf("%d ",c[i]);
    }
    return 0;
}