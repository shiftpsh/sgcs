#include <stdio.h>

char* LGame(char word[]);
int isVowel(char c);
char toLowerCase(char c);

int main() {
	char c[500], x, *res;
	int i = 0;

	while (1) {
		scanf("%c", &x);
		if (x == '\n') {
			c[i] = '\0';
			break;
		}
		c[i] = x;
		i++;
	}

	LGame(c);

	return 0;
}

char* LGame(char word[]) {
	char res[1000];
	char w[22];
	char a[22], b[22];
	int widx = 0, ridx = 0, i, j, strlen = 0, alen, blen, flag;
	char terminator = ' ';
	int process = 1;

	for (i = 0; i < 1000; i++) res[i] = ' ';
	for (i = 0; i < 500; i++) if (word[i] == '\0') {
		strlen = i;
		break;
	}

	while (widx < strlen) {
		for (i = 0; i < 22; i++) {
			w[i] = ' ';
			a[i] = ' ';
			b[i] = ' ';
		}

		i = 0;
		flag = 0;
		alen = 0;
		blen = 0;

		while (1) {
			w[i] = word[widx];

			if (w[i] == ' ' || w[i] == '.' || w[i] == '!' || w[i] == '?' || w[i] == '\0') {
				terminator = w[i];
				break;
			}

			i++;
			widx++;
		}

		if (terminator == '\0') {
			process = 0;
		}

		for (j = 0; j < i; j++) {
			if (isVowel(w[j]) || flag) {
				flag = 1;
				b[blen] = w[j];
				blen++;
			} else {
				a[alen] = w[j];
				alen++;
			}
		}

		for (j = 0; j < blen; j++) {
			res[ridx] = b[j];
			ridx++;
		}

		for (j = 0; j < alen; j++) {
			res[ridx] = toLowerCase(a[j]);
			ridx++;
		}

		if (res[ridx - 1] != 'A' && res[ridx - 1] != 'a' && alen + blen != 0) {
			res[ridx] = 'a';
			ridx++;
		}

		if (alen + blen != 0) {
			res[ridx] = 'y';
			ridx++;
		}
		
		res[ridx] = terminator;
		ridx++;

		widx++;
	}

	res[ridx] = '\0';

	printf("%s", res);

	return res;
}

int isVowel(char c) {
	return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
		c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

char toLowerCase(char c) {
	if ('A' < c && c < 'Z') return c + 0x20;
	else return c;
}