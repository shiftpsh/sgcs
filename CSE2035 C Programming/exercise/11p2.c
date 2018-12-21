#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strncpy(char*, char*, int);
void initialization(char*, int);

int main() {
	int i;
	char* str1;
	char str[20];

	gets(str);

	str1 = (char*)malloc((strlen(str) + 1) * sizeof(char));
	strcpy(str1, str);

	for (i = 0; i < strlen(str1) + 1; i++) {
		initialization(str, strlen(str));
		my_strncpy(str, str1, i);
		printf("%s\n", str);
	}

	free(str1);

	return 0;
}

char *my_strncpy(char* a, char* b, int n) {
	int i;
	for (i = 0; i < n; i++) {
		a[i] = b[i];
	}
}

void initialization(char* a, int n) {
	int i;
	for (i = 0; i < n; i++) {
		a[i] = '*';
	}
}