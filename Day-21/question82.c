//wap tp reverse a string.
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "hello";
    int start = 0;
    int end = strlen(str) - 1;
    char temp;

    // Swap characters until the pointers meet in the middle
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }

    printf("%s\n", str); // Output: olleh
    return 0;
}
