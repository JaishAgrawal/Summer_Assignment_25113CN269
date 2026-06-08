//wap tp print character triangle.
#include <stdio.h>

void printCharacterTriangle(int rows) {
    // Outer loop for each row
    for(int i = 1; i <= rows; i++) {
        // Inner loop to print characters from A to the ith character
        for(int j = 1; j <= i; j++) {
            printf("%c", 'A' + j - 1);
        }
        printf("\n");  // Move to next line
    }
}

int main() {
    int numRows;
    
    printf("Enter the number of rows for the character triangle: ");
    scanf("%d", &numRows);
    
    printCharacterTriangle(numRows);  // Print the pattern
    
    return 0;
}