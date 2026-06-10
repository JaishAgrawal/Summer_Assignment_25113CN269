//wap tp print character pyramid pattern.
#include <stdio.h>

void printPattern(int n) {
    for (int i = 0; i < n; i++) {
        // Print increasing letters
        for (int j = 0; j <= i; j++) {
            printf("%c", 'A' + j);
        }
        // Print decreasing letters
        for (int j = i - 1; j >= 0; j--) {
            printf("%c", 'A' + j);
        }
        printf("\n"); // Move to next line
    }
}

int main() {
    int rows = 5; // Number of rows to print
    printPattern(rows);
    return 0;
}
