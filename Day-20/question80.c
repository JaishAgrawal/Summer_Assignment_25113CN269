//wap to find column wise sum.
#include <stdio.h>

int main() {
    int rows, cols;
    int matrix[100][100];

    // Get matrix dimensions from user
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Input matrix elements
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Display the original matrix
    printf("\nThe entered matrix is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Calculate and print column-wise sum
    // Outer loop controls columns, Inner loop controls rows
    for (int j = 0; j < cols; j++) {
        int colSum = 0; 
        for (int i = 0; i < rows; i++) {
            colSum += matrix[i][j]; // Summing row elements for the fixed column 'j'
        }
        printf("Sum of Column %d = %d\n", j + 1, colSum);
    }

    return 0;
}
