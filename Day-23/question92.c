// wap to find maximum occurring character

#include <stdio.h>
#include <string.h>

int main(void) {
	char s[1000];
	if (!fgets(s, sizeof s, stdin)) return 0;
	// remove trailing newline
	size_t len = strlen(s);
	if (len && s[len-1] == '\n') s[len-1] = '\0';

	int freq[256] = {0};
	for (size_t i = 0; s[i]; ++i) {
		unsigned char c = (unsigned char)s[i];
		freq[c]++;
	}

	int maxf = 0;
	unsigned char maxc = 0;
	for (int i = 0; i < 256; ++i) {
		if (freq[i] > maxf) {
			maxf = freq[i];
			maxc = (unsigned char)i;
		}
	}

	if (maxf > 0)
		printf("%c %d\n", maxc, maxf);
	return 0;
}
