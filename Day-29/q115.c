//Write a program to Create menu-driven string operations system.
#include<stdio.h>
#include<string.h>
#include<ctype.h>

void inputString(char str[]) {
    printf("Enter string: ");
    scanf("%99s", str);
}

void displayString(char str[]) {
    printf("String: %s\n", str);
}

void stringLength(char str[]) {
    printf("Length: %d\n", strlen(str));
}

void reverseString(char str[]) {
    printf("Reversed: ");
    for (int i = strlen(str) - 1; i >= 0; i--)
        printf("%c", str[i]);
    printf("\n");
}

void searchChar(char str[]) {
    char ch;
    printf("Enter character to search: ");
    scanf(" %c", &ch);
    for (int i = 0; str[i]; i++) {
        if (str[i] == ch) {
            printf("Found at index %d\n", i);
            return;
        }
    }
    printf("Not found\n");
}

void concatenateStrings(char str[], char str2[]) {
    printf("Enter second string: ");
    scanf("%99s", str2);
    strcat(str, str2);
    printf("Concatenated: %s\n", str);
}

void compareStrings(char str[], char str2[]) {
    printf("Enter second string: ");
    scanf("%99s", str2);
    if (strcmp(str, str2) == 0)
        printf("Strings are equal\n");
    else
        printf("Strings are not equal\n");
}

void checkPalindrome(char str[]) {
    int len = strlen(str), isPalin = 1;
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            isPalin = 0;
            break;
        }
    }
    printf("%s\n", isPalin ? "String is palindrome" : "String is not palindrome");
}

void countVowels(char str[]) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        char c = tolower(str[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            count++;
    }
    printf("Vowels: %d\n", count);
}

int main() {
    char str[100], str2[100];
    int choice;

    while (1) {
        printf("\n1. Input String\n2. Display String\n3. Length\n4. Reverse\n");
        printf("5. Search Character\n6. Concatenate\n7. Compare\n8. Palindrome\n");
        printf("9. Count Vowels\n10. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: inputString(str); break;
            case 2: displayString(str); break;
            case 3: stringLength(str); break;
            case 4: reverseString(str); break;
            case 5: searchChar(str); break;
            case 6: concatenateStrings(str, str2); break;
            case 7: compareStrings(str, str2); break;
            case 8: checkPalindrome(str); break;
            case 9: countVowels(str); break;
            case 10: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
