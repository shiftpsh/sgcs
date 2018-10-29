#include <stdio.h>

void calculate(char op, float a, float b);
void addition(float a, float b);
void subtraction(float a, float b);
void multiplication(float a, float b);
void division(float a, float b);

int main(void) {
	float a, b;
	char op;

	printf("Operator (+, -, *, /)\n");
	printf("Please enter the formula. (ex : 12.3 + 5.5)\n");
	scanf("%f %c %f", &a, &op, &b);
	calculate(op, a, b);

	return 0;
}

void calculate(char op, float a, float b) {
	switch (op) {
	case '+':
		addition(a, b);
		break;
	case '-':
		subtraction(a, b);
		break;
	case '*':
		multiplication(a, b);
		break;
	case '/':
		division(a, b);
		break;
	default:
		printf("Invalid operator : '%c'.\n", op);
		break;
	}

	return;
}

void addition(float a, float b) {
	printf("%.2f + %.2f = %.2f\n", a, b, a + b);
	return;
}

void subtraction(float a, float b) {
	printf("%.2f - %.2f = %.2f\n", a, b, a - b);
	return;
}

void multiplication(float a, float b) {
	printf("%.2f * %.2f = %.2f\n", a, b, a * b);
	return;
}

void division(float a, float b) {
	switch (b == 0) {
	case 0: // b != 0
		printf("%.2f / %.2f = %.2f\n", a, b, a / b);
		break;
	case 1: // b == 0
		printf("Division by zero.\n");
		break;
	}
	return;
}