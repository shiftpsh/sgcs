#include <stdio.h>

void Josephus(int n, int k);

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	Josephus(n, k);

	return 0;
}

void Josephus(int n, int k) {
	int i, count = 0, x = 0;
	int r = n - k;
	int flag[100000];
	for (i = 0; i < 100000; i++) flag[i] = 0;

	i = k % n - 1;
	while (count < r) {
		if (count == r - 1) {
			printf("%d", i + 1);
		} else {
			printf("%d ", i + 1);
		}
		flag[i] = 1;
		x = 0;
		while (x < k) {
			x++;
			i++;
			while (flag[i] == 1) i++;
			i %= n;
		}
		count++;
	}

	printf("\n");
	return;
}