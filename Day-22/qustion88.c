//wap to remove spaces from string.
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[256];
    char result[256];
    int i, j = 0;

    if (fgets(str, sizeof(str), stdin) == NULL)
        return 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '\r') {
            result[j++] = str[i];
        }
    }
    result[j] = '\0';

    printf("%s", result);
    return 0;
}
