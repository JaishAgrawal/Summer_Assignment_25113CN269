//wap to check anagram strings.
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int areAnagrams(char *str1, char *str2) {
    int count[26] = {0};
    
    if (strlen(str1) != strlen(str2)) {
        return 0;
    }
    
    for (int i = 0; str1[i] != '\0'; i++) {
        char c = tolower(str1[i]);
        if (c >= 'a' && c <= 'z') {
            count[c - 'a']++;
        }
    }
    
    for (int i = 0; str2[i] != '\0'; i++) {
        char c = tolower(str2[i]);
        if (c >= 'a' && c <= 'z') {
            count[c - 'a']--;
        }
    }
    
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            return 0;
        }
    }
    
    return 1;
}

int main() {
    char str1[100], str2[100];
    
    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';
    
    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';
    
    if (areAnagrams(str1, str2)) {
        printf("Strings are anagrams\n");
    } else {
        printf("Strings are not anagrams\n");
    }
    
    return 0;
}
