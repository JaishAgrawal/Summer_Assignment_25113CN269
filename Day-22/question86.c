//wap to count words in a sentence.
#include <stdio.h>
#include <ctype.h>

int count_words(const char *str) {
    int count = 0;
    int in_word = 0; // Acts as a boolean flag (0 = false, 1 = true)

    while (*str) {
        // isspace() checks for spaces, tabs, and newline characters
        if (isspace((unsigned char)*str)) {
            in_word = 0;
        } 
        // If it's a non-space character and we aren't already tracking a word
        else if (!in_word) {
            in_word = 1;
            count++;
        }
        str++; // Move to the next character
    }

    return count;
}

int main() {
    char sentence[1000];

    printf("Enter a sentence: ");
    // fgets safely reads the entire line, including spaces
    if (fgets(sentence, sizeof(sentence), stdin) != NULL) {
        int words = count_words(sentence);
        printf("Number of words: %d\n", words);
    }

    return 0;
}
