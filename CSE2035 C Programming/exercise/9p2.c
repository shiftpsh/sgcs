#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int strlen(char[]);
char* upper_to_lower(char[]);
char* lower_to_upper(char[]);

int main() {
	char a[] = "123AbCdEfGh";
	char b[] = "There¡¯s no Free Lunch";

	printf("%s\n", upper_to_lower(a));
	printf("%s\n", lower_to_upper(a));

	printf("%s\n", upper_to_lower(b));
	printf("%s\n", lower_to_upper(b));

	return 0;
}

int strlen(char str[]) {
	int i = 0;

	while (str[i] != '\0') i++;

	return i;
}

char* upper_to_lower(char str[]) {
	int len = strlen(str), i;
	char* lower = (char*)malloc((len + 1) * sizeof(char));
	lower[len] = '\0';

	for (i = 0; i < len; i++) {
		if ('A' <= str[i] && str[i] <= 'Z') {
			lower[i] = str[i] + 0x20;
		}
		else if ('a' <= str[i] && str[i] <= 'z') {
			lower[i] = str[i];
		}
		else {
			lower[i] = str[i];
		}
	}

	return lower;
}

char* lower_to_upper(char str[]) {
	int len = strlen(str), i;
	char* upper = (char*)malloc((len + 1) * sizeof(char));
	upper[len] = '\0';

	for (i = 0; i < len; i++) {
		if ('A' <= str[i] && str[i] <= 'Z') {
			upper[i] = str[i];
		}
		else if ('a' <= str[i] && str[i] <= 'z') {
			upper[i] = str[i] - 0x20;
		}
		else {
			upper[i] = str[i];
		}
	}

	return upper;
}