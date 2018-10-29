#include <stdio.h>

int main() {
	FILE *inFile, *outFile;
	char name[20];
	float midtermScore, finalScore, sum = 0.0, average, totalAverage;
	int res, count = 0;

	inFile = fopen("student.txt", "r");
	outFile = fopen("output33.txt", "w");

	if (inFile == NULL) {
		printf("Cannot read file.\n");
		return 1;
	}

	if (outFile == NULL) {
		printf("Cannot write file.\n");
		return 1;
	}

	while (1) {
		res = fscanf(inFile, "%s%f%f", &name, &midtermScore, &finalScore);
		if (res == EOF) break;
		
		sum += midtermScore;
		sum += finalScore;
		count += 2;
	}

	totalAverage = sum / count;
	fclose(inFile);

	inFile = fopen("student.txt", "r");

	fprintf(outFile, "student   average grade\n");

	while (1) {
		res = fscanf(inFile, "%s%f%f", &name, &midtermScore, &finalScore);
		if (res == EOF) break;
		
		average = (midtermScore + finalScore) / 2;
		
		if (average >= totalAverage) {
			fprintf(outFile, "%-8s %6.2f   p\n", name, average);
		} else {
			fprintf(outFile, "%-8s %6.2f   f\n", name, average);
		}
	}

	fprintf(outFile, "Total average: %.2f\n", totalAverage);

	fclose(inFile);
	fclose(outFile);

	return 0;
}