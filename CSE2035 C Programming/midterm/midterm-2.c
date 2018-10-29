#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findNumberAndSum(char*, int);

int main() {
	char str[1001];
	scanf("%s", &str);

	printf("%d", findNumberAndSum(str, strlen(str)));

	return 0;
}

int findNumberAndSum(char* text, int length) {
	int sum = 0, temp = 0, i;
	char last = '\0';

	for (i = 0; i < length; i++) {
		if ('0' <= text[i] && text[i] <= '9') {
			temp *= 10;
			temp += text[i] - '0';
		}
		else {
			sum += temp;
			temp = 0;
		}
	}

	sum += temp;
	return sum;
}