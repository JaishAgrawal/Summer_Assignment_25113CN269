#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    char result[100];
    int seen[256] = {0};  // Array to track which characters we've seen (for ASCII)
    int resultIndex = 0;
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  // Remove newline
    
    // Remove duplicate characters
    for (int i = 0; str[i] != '\0'; i++)
    {
        // If we haven't seen this character before
        if (!seen[(unsigned char)str[i]])
        {
            // Mark it as seen
            seen[(unsigned char)str[i]] = 1;
            // Add it to result
            result[resultIndex++] = str[i];
        }
    }
    
    result[resultIndex] = '\0';  // Null terminate the result string
    
    printf("\nOriginal string: %s\n", str);
    printf("String after removing duplicates: %s\n", result);
    
    return 0;
}