//wap to find maximum frequency element in array
#include<stdio.h>
int main()
{
    int a[100],n,i,j,max_count=0,count=0,max_element;
    printf("Enter the size of array:");
    scanf("%d",&n);
    printf("Enter the elements of array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        count=1;
        for(j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
            {
                count++;
            }
        }
        if(count>max_count)
        {
            max_count=count;
            max_element=a[i];
        }
    }
    printf("The maximum frequency element is:%d",max_element);
    return 0;
}