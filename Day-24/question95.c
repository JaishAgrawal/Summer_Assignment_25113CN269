#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[500];
    char word[100];
    char longestWord[100] = "";
    int maxLength = 0;
    int wordLength = 0;
    int wordIndex = 0;
    
    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  // Remove newline
    
    // Parse the string word by word
    for (int i = 0; str[i] != '\0'; i++)
    {
        // If current character is not a space, add it to word
        if (str[i] != ' ')
        {
            word[wordIndex++] = str[i];
        }
        else
        {
            // End of word found
            if (wordIndex > 0)
            {
                word[wordIndex] = '\0';
                wordLength = strlen(word);
                
                // Check if this word is longer than the previous longest
                if (wordLength > maxLength)
                {
                    maxLength = wordLength;
                    strcpy(longestWord, word);
                }
                
                wordIndex = 0;
            }
        }
    }
    
    // Handle the last word (if string doesn't end with space)
    if (wordIndex > 0)
    {
        word[wordIndex] = '\0';
        wordLength = strlen(word);
        
        if (wordLength > maxLength)
        {
            maxLength = wordLength;
            strcpy(longestWord, word);
        }
    }
    
    printf("\nLongest word: \"%s\"\n", longestWord);
    printf("Length: %d characters\n", maxLength);
    
    return 0;
}
