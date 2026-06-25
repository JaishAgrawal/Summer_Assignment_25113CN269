#include <stdio.h>
#include <string.h>

int main(void)
{
    char names[10][30];
    int n;

    printf("Enter number of names (max 10): ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Name %d: ", i + 1);
        scanf("%29s", names[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(names[i], names[j]) > 0) {
                char temp[30];
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }

    printf("\nSorted names:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}


