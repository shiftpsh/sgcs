#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct CoinBox {
	int n500, n100, n50, n10;
};

int main() {
	int m;
	scanf("%d", &m);

	struct CoinBox box = {
		m / 500, (m % 500) / 100, (m % 100) / 50, (m % 50) / 10
	};

	printf("%d\n%d\n%d\n%d\n", box.n500, box.n100, box.n50, box.n10);

	return 0;
}