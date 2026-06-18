//wap tobinary search in array.
#include<stdio.h>
int main()
{
    int a[100],n,i,low,high,mid,key,flag=0;
    printf("Enter the size of array:");
    scanf("%d",&n);
    printf("Enter the elements of array:");
    for(i=0;i<n;i++)
    {   
        scanf("%d",&a[i]);
    }
    printf("Enter the key to be searched:");
    scanf("%d",&key);   
    low=0;
    high=n-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==key)
        {
            flag=1;
            break;
        }
        else if(a[mid]<key)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    if(flag==1)
    {
        printf("Key found at position %d",mid+1);
    }
    else
    {
        printf("Key not found");
    }
    return 0;
}