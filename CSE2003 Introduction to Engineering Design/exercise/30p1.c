#include <stdio.h>

double parseDouble(char str[10]);

int main() {
	char str[10];
	int i;

	for (i = 0; i < 10; i++) {
		scanf("%c", &str[i]);
		if (str[i] == '\n') break;
	}

	printf("Result: %lf\n", parseDouble(str));

	return 0;
}

double parseDouble(char str[10]) {
	int i, l = 9; // l = last index of str
	double res = 0;
	int sign = 0, dotPosition = -1;

	for (i = 0; i < 10; i++) {
		char c = str[i];

		if (c == '-') {
			sign = -1;
		} else if (c == '.') {
			dotPosition = i;
		} else if ('0' <= c && c <= '9') {
			res *= 10;
			res += c - '0';
		} else {
			l = i - 1;
			break;
		}
	}

	if (dotPosition != -1) {
		while (dotPosition < l) {
			res /= 10;
			dotPosition++;
		}
	}

	if (sign) res *= -1;

	return res;
}