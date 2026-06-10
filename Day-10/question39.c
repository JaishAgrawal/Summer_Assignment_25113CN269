//wap tp print number pyramid pattern.
#include <stdio.h>

int main() {
    int rows = 5;

    for (int i = 1; i <= rows; i++) {
        // Print increasing sequence from 1 to i
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }
        
        // Print decreasing sequence from i-1 down to 1
        for (int j = i - 1; j >= 1; j--) {
            printf("%d", j);
        }
        
        // Move to the next line
        printf("\n");
    }

    return 0;
}
