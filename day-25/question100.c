#include <stdio.h>
#include <string.h>

int main(void)
{
    char words[10][30];
    int n;

    printf("Enter number of words (max 10): ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Word %d: ", i + 1);
        scanf("%29s", words[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strlen(words[i]) > strlen(words[j])) {
                char temp[30];
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            }
        }
    }

    printf("\nWords sorted by length:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}

