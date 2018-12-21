#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int i, words = 0, flag = 0;
	char str[10000], last = '\0';
	gets(&str);

	for (i = 0; i < strlen(str); i++) {
		if (!flag && str[i] != ' ') {
			flag = 1;
		}
		if (flag) {
			if (last != ' ' && str[i] == ' ') {
				words++;
			}
		}

		last = str[i];
	}

	if (last != ' ') words++;

	printf("%d\n", words);

	return 0;
}
