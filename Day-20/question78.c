//wap to check symmetric matrix.
#include <stdio.h>

int main() {
    int rows, cols;
    int matrix[10][10];
    int isSymmetric = 1; // Flag initialized to 1 (true)

    // Step 1: Input dimensions
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Step 2: Validate if it is a square matrix
    if (rows != cols) {
        printf("The matrix is NOT symmetric (it must be a square matrix).\n");
        return 0;
    }

    // Step 3: Input matrix elements
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Step 4: Check for symmetry
    for (int i = 0; i < rows; i++) {
        for (int j = i + 1; j < cols; j++) { // j starts from i + 1 to avoid redundant checks
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0; // Found a mismatch
                break;
            }
        }
        if (!isSymmetric) {
            break;
        }
    }

    // Step 5: Print the result
    if (isSymmetric) {
        printf("\nThe given matrix is a Symmetric Matrix.\n");
    } else {
        printf("\nThe given matrix is NOT a Symmetric Matrix.\n");
    }

    return 0;
}
