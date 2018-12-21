#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int strlen(char[]);
char* crypt(int, char[]);

int main() {
	int i, n;
	char str[50];
	scanf("%s", &str);

	srand(time(NULL));

	for (i = 0; i < 5; i++) {
		n = rand() % 25 + 1;
		printf("%2d %s\n", n, crypt(n, str));
	}

	return 0;
}

int strlen(char str[]) {
	int i = 0;

	while (str[i] != '\0') i++;

	return i;
}

char* crypt(int key, char str[]) {
	int l = strlen(str), i, x;
	char* res = (char*)malloc((l + 1) * sizeof(char));
	res[l] = '\0';

	for (i = 0; i < l; i++) {
		x = str[i] - 'a';
		x += key;
		x %= 26;
		res[i] = x + 'A';
	}

	return res;
}