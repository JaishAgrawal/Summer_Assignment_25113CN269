
#include <stdio.h>
#include <string.h>

int main(void) {
	char s[1001];
	if (fgets(s, sizeof(s), stdin) == NULL) return 0;
	size_t n = strlen(s);
	if (n > 0 && s[n-1] == '\n') s[--n] = '\0';

	int freq[256] = {0};
	for (size_t i = 0; i < n; ++i) freq[(unsigned char)s[i]]++;

	for (size_t i = 0; i < n; ++i) {
		if (freq[(unsigned char)s[i]] == 1) {
			printf("%c\n", s[i]);
			return 0;
		}
	}

	printf("No non-repeating character\n");
	return 0;
}

