#include <stdio.h>

int main() {
	FILE *aFile, *bFile, *outFile;
	char aName[100], bName[100], aChar = ' ', bChar = ' ';
	int chars = 0, same = 0;

	printf("Input first filename  : ");
	scanf("%s", &aName);
	printf("Input second filename : ");
	scanf("%s", &bName);

	aFile = fopen(aName, "r");
	bFile = fopen(bName, "r");
	outFile = fopen("output", "w");

	if (aFile == NULL) {
		printf("Cannot read first file.\n");
		return 1;
	}

	if (bFile == NULL) {
		printf("Cannot read second file.\n");
		return 1;
	}

	if (outFile == NULL) {
		printf("Cannot write to storage.\n");
		return 1;
	}

	while (1) {
		aChar = fgetc(aFile);
		while (aChar == ' ' || aChar == '\n') aChar = fgetc(aFile);
		if (aChar == EOF) break;

		bChar = fgetc(bFile);
		while (bChar == ' ' || bChar == '\n') bChar = fgetc(bFile);
		if (bChar == EOF) break;

		chars++;
		if (aChar == bChar) same++;
	}

	fprintf(outFile, "Total characters : %d\n", chars);
	fprintf(outFile, "Same  characters : %d\n", same);
	fprintf(outFile, "%.3f%%\n", (float) same / chars * 100);

	fclose(aFile);
	fclose(bFile);
	fclose(outFile);

	return 0;
}