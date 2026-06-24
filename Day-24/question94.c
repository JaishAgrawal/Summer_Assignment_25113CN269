#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to compress a string
void compressString(char *str, char *compressed)
{
    int count = 0;
    int compressedIndex = 0;
    
    for (int i = 0; str[i] != '\0'; i++)
    {
        count = 1;
        
        // Count consecutive characters
        while (str[i] == str[i + 1])
        {
            count++;
            i++;
        }
        
        // Add character to compressed string
        compressed[compressedIndex++] = str[i];
        
        // Add count if greater than 1
        if (count > 1)
        {
            // Convert count to string and add to compressed
            if (count >= 10)
            {
                compressed[compressedIndex++] = '0' + (count / 10);
                compressed[compressedIndex++] = '0' + (count % 10);
            }
            else
            {
                compressed[compressedIndex++] = '0' + count;
            }
        }
    }
    
    compressed[compressedIndex] = '\0';
}

int main()
{
    char str[100];
    char compressed[100];
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  // Remove newline
    
    compressString(str, compressed);
    
    printf("Original string: %s\n", str);
    printf("Compressed string: %s\n", compressed);
    
    // Also display the compression ratio
    printf("Original length: %lu, Compressed length: %lu\n", strlen(str), strlen(compressed));
    
    return 0;
}
