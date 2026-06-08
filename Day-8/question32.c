//wap to print repeated number pattern.
#include <stdio.h>

void printNumberPattern(int rows) {
    // Outer loop for each row
    for(int i = 1; i <= rows; i++) {
        // Inner loop to print the number 'i' exactly 'i' times
        for(int j = 1; j <= i; j++) {
            printf("%d ", i);
        }
        printf("\n");  // Move to next line after each row
    }
}

int main() {
    int numRows;
    
    printf("Enter the number of rows for the pattern: ");
    scanf("%d", &numRows);
    
    printNumberPattern(numRows);  // Call function to display the pattern
    
    return 0;
}