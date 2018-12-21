#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char unit[] = {'K', 'M', 'G', 'T', 'P'}, str[17];
	int l, i, basel, sigl, sig = 0, flag = 1;

	scanf("%16s", &str);
	l = strlen(str);
	basel = (l - 1) / 3;
	sigl = (l - 1) % 3 + 1;

	for (i = 0; i < l; i++) {
		if (!('0' <= str[i] && str[i] <= '9')) {
			flag = 0;
			break;
		}
	}

	if (!flag) {
		printf("%s\n", str);
	}
	else {
		if (basel == 0) {
			printf("%s\n", str);
		}
		else {
			for (i = 0; i < sigl; i++) {
				sig *= 10;
				sig += str[i] - '0';
			}

			printf("%d%c\n", sig, unit[basel - 1]);
		}
	}

	return 0;
}
