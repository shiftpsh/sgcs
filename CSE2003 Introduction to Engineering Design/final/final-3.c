#include <stdio.h>

float returnScore(int scores[]);
char grade(float score);

int main() {
	FILE *in;
	int scores[3], i;
	float score;

	in = fopen("input.txt", "r");
	if (in == NULL) {
		printf("Input error.\n");
		return 1;
	}

	for (i = 0; i < 3; i++) {
		fscanf(in, "%d", &scores[i]);
	}

	score = returnScore(scores);

	printf("%.2f %c\n", score, grade(score));

	fclose(in);

	return 0;
}

float returnScore(int scores[]) {
	float sum = 0.25 * scores[0] + 0.25 * scores[1] + 0.5 * scores[2];

	return sum;
}

char grade(float score) {
	if (score >= 95) return 'A';
	else if (score >= 80) return 'B';
	else if (score >= 50) return 'C';
	else return 'D';
}