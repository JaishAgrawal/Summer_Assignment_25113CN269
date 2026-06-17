//wap to union of two arrays.
#include<stdio.h>
int main()
{
    int a[100],b[100],c[200],n1,n2,i,j,k=0,flag;
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
        c[k++]=a[i];
    }
    for(i=0;i<n2;i++)
    {
        flag=0;
        for(j=0;j<n1;j++)
        {
            if(b[i]==a[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            c[k++]=b[i];
        }
    }
    printf("The union of two arrays is:");
    for(i=0;i<k;i++)
    {
        printf("%d ",c[i]);
    }
    return 0;
}