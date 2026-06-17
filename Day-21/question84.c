//wap to conver lowercase into uppercase.
#include <stdio.h>

void toUpperCase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        // Check if character is lowercase
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32; // Convert by modifying ASCII value
        }
    }
}

int main() {
    char text[] = "hello world";
    
    toUpperCase(text);
    
    printf("%s\n", text); // Output: HELLO WORLD
    return 0;
}
