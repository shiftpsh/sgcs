#include <stdio.h>

/**
 *  April 19th, 2018
 *  CSE2003 Midterm Exam
 *  Problem #2
 */

void checkWB(char col, int row, char *answer);

int main(void) {
	char col, answer;
	int row;

	scanf("%c%d", &col, &row);
	checkWB(col, row, &answer);
	printf("%c\n", answer);

	return 0;
}

void checkWB(char col, int row, char *answer) {
	int _col = col - 0x60; // 'a' = 0x61

	if ((_col + row) % 2 == 1) {
		*answer = 'W';
	} else {
		*answer = 'B';
	}

	return;
}