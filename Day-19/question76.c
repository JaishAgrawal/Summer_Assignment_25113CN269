//wap to find diagonal sum.
#include <stdio.h>

int main() {
    int n;
    int principal_sum = 0;
    int secondary_sum = 0;

    // Get matrix size from user
    printf("Enter the size of the square matrix (N x N): ");
    scanf("%d", &n);

    int matrix[n][n];

    // Input elements of the matrix
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate diagonal sums efficiently in a single loop
    for (int i = 0; i < n; i++) {
        principal_sum += matrix[i][i];          // Top-left to bottom-right
        secondary_sum += matrix[i][n - i - 1];  // Top-right to bottom-left
    }

    // Print the results
    printf("\nSum of Principal Diagonal: %d\n", principal_sum);
    printf("Sum of Secondary Diagonal: %d\n", secondary_sum);

    return 0;
}
