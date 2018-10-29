#include <stdio.h>

int asciiCode(char c);

int main(void) {
	char c;

	printf("Enter 1 Character : ");
	scanf("%c", &c);

	printf("ASCII code of [%c] is [%d]\n", c, asciiCode(c));

	return 0;
}

int asciiCode(char c) {
	return (int) c;
}