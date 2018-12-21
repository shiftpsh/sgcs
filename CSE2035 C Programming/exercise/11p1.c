#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void split_string(char*, char*, char*);

int main() {
	char str[51], string_1[51], string_2[51];
	gets(str);

	split_string(str, string_1, string_2);

	printf("[%s] -> [%s] [%s]\n", str, string_1, string_2);

	return 0;
}

void split_string(char* str, char* string_1, char* string_2) {
	int i;
	int l = strlen(str);
	int m = l / 2;

	strcpy(string_1, str);
	strcpy(string_2, str);

	string_1[m] = '\0';

	for (i = 0; i <= m; i++) {
		string_2[i] = string_2[i + m];
	}

	string_2[m] = '\0';
}