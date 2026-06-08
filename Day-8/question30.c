//wap tp print number triangle.
#include<stdio.h>

void numberTriangle(int n)
{
    for(int i=1; i<=n; i++) // Loop through each row
    {
        for(int j=1; j<=i; j++) // Loop to print numbers in each row
        {
            printf("%d", j);
        }
        printf("\n"); // Move to the next line after printing each row
    }
}

int main()
{
    int rows;
    printf("Enter the number of rows for the number triangle: ");
    scanf("%d", &rows); // Read the number of rows from user input
    numberTriangle(rows); // Call the function to print the number triangle
    return 0;
}