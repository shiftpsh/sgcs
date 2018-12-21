#include <stdio.h>

void func_gcd(int a, int b, int* gcd);

int main(void) {
	int a, b, gcd;

	printf("Input first number  : ");
	scanf("%d", &a);
	printf("Input second number : ");
	scanf("%d", &b);

	func_gcd(a, b, &gcd);

	printf("GCD : %d\n", gcd);
	return 0;
}

void func_gcd(int a, int b, int* gcd) {
	while (a % b != 0 && b % a != 0) {
		if (a > b) {
			a %= b;
		} else {
			b %= a;	
		}
	}

	if (a % b == 0) {
		*gcd = b;
	} else {
		*gcd = a;
	}
}