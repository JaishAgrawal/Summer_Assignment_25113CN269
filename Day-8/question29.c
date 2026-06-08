//wap to print half pyramid pattern.
#include<stdio.h>

void halfPyramid(int n)
{
    for(int i=1; i<=n; i++) // Loop through each row
    {
        for(int j=1; j<=i; j++) // Loop to print stars in each row
        {
            printf("* ");
        }
        printf("\n"); // Move to the next line after printing each row
    }
}

int main()
{
    int rows;
    printf("Enter the number of rows for the half pyramid: ");
    scanf("%d", &rows); // Read the number of rows from user input
    halfPyramid(rows); // Call the function to print the half pyramid
    return 0;
}