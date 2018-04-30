#include <stdio.h>

/**
 *  April 19th, 2018
 *  CSE2003 Midterm Exam
 *  Problem #3
 */

void caesar(char* alphabet, int key);

int main(void) {
	int key;
	char a, b, c;

	scanf("%d %c%c%c", &key, &a, &b, &c);

	caesar(&a, key);
	caesar(&b, key);
	caesar(&c, key);

	printf("%c%c%c\n", a, b, c);

	return 0;
}

void caesar(char* alphabet, int key) {
	/**  
	 *  Problem never stated that key falls
	 *  in -26 .. 26
	 *
	 *  'A' = 0x41; 'a' = 0x61
	 */

	int alphabetIndex = *alphabet - 0x61;

	alphabetIndex += key;
	alphabetIndex %= 26;

	if (alphabetIndex < 0) alphabetIndex += 26;

	*alphabet = alphabetIndex + 0x61;

	return;
}