#include <stdio.h>

int main() {
	FILE* in;
	int ref[26], i, c;

	for (i = 0; i < 26; i++) ref[i] = 0;

	in = fopen("input_39.txt", "r");

	if (in == NULL) {
		printf("File open error.\n");
		return 1;
	}

	while (1) {
		c = fgetc(in);
		if (c == EOF) break;

		if ('A' <= c && c <= 'Z') ref[c - 0x41]++;
		if ('a' <= c && c <= 'z') ref[c - 0x61]++;
	}

	fclose(in);

	for (i = 0; i < 26; i++) {
		printf("%c: %4d ", (char)(i + 0x41), ref[i]);
	}

	printf("\n");

	return 0;
}