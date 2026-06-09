//wap tp print repeated character pattern 
#include <stdio.h>

int main() {
    int rows;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    char ch1 = 'A'; 
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%c", ch1);
        }
        ch1++; // Move to the next character for the next row
        printf("\n");
    }
    return 0;
}
