#include <stdio.h>

int main() {
	FILE *inFile, *outFile;
	double a, b, c, result;
	char op, _;
	int res;

	inFile = fopen("input32.txt", "r");
	outFile = fopen("output32.txt", "w");

	if (inFile == NULL) {
		printf("Cannot read file.\n");
		return 1;
	}

	if (outFile == NULL) {
		printf("Cannot write file.\n");
		return 1;
	}

	while (1) {
		res = fscanf(inFile, "%lf %c %lf %c %lf", &a, &op, &b, &_, &c);
		if (res == EOF) break;
		
		switch (op) {
			case '+': result = a + b; break;
			case '-': result = a - b; break;
			case '*': result = a * b; break;
			case '/': result = a / b; break;
			case '%': result = (int) a % (int) b; break;
		}

		if (c == result) {
			fprintf(outFile, "%.2lf %c %.2lf = %.2lf correct\n", a, op, b, c);
		} else {
			fprintf(outFile, "%.2lf %c %.2lf = %.2lf incorrect\n", a, op, b, c);
		}
	}

	fclose(inFile);
	fclose(outFile);

	return 0;
}