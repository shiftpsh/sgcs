#include <stdio.h>

int main() {
	int a[5], b[5];
	int i;
	int flag = 1;

	for (i = 0; i < 5; i++) {
		scanf("%d", &a[i]);
	}

	for (i = 0; i < 5; i++) {
		scanf("%d", &b[i]);
	}

	for (i = 0; i < 5; i++) {
		if (a[i] != b[i]) {
			flag = 0;
			break;
		}
	}

	if (flag) {
		printf("true\n");
	} else {
		printf("false\n");
	}
}