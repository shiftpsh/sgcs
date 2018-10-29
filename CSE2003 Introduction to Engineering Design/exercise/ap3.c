#include <stdio.h>

void dec2oct(int* a, int* b, int* c, int* d, int n);
void dec2hex(char* x, char* y, char* z, int n);
char digit2hex(int l);

int main(void) {
	int n;

	int a, b, c, d;
	char x, y, z;

	scanf("%d", &n);

	dec2oct(&a, &b, &c, &d, n);
	dec2hex(&x, &y, &z, n);

	printf("%%o      : %04o\n", n);
	printf("dec2oct : %d%d%d%d\n", a, b, c, d);
	printf("%%X      :  %03X\n", n);
	printf("dec2hex :  %c%c%c\n", x, y, z);

	return 0;
}

void dec2oct(int* a, int* b, int* c, int* d, int n) {
	*a = n / 8 / 8 / 8     ;
	*b = n / 8 / 8      % 8;
	*c = n / 8          % 8;
	*d = n              % 8;

	return;
}

void dec2hex(char* x, char* y, char* z, int n) {
	*x = digit2hex(n / 16 / 16      );
	*y = digit2hex(n / 16       % 16);
	*z = digit2hex(n            % 16);

	return;
}

char digit2hex(int l) {
	if (l < 9) return (char) (l + 0x30);
	else return (char) (l - 10 + 0x41);
}