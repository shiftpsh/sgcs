#include <stdio.h>

void toUpperCase(char str[]);

int main() {
	char str[50];
	int i, l = 50;

	for (i = 0; i < 50; i++) {
		scanf("%c", &str[i]);
		if (str[i] == '\n') {
			l = i;
			break;
		}
	}

	toUpperCase(str);

	for (i = 0; i < l; i++) {
		printf("%c", str[i]);
	}

	printf("\n");
}

void toUpperCase(char str[]) {
	int i;

	for (i = 0; i < 50; i++) {
		if ('a' <= str[i] && str[i] <= 'z') {
			str[i] -= 0x20;
		}
	}

	return;
}