#include <stdio.h>

int check (char binary[]);
int biToDec (char binary[]);

int main() {
	char binary[100];

	printf("Enter binary number : ");
	scanf("%s", binary);

	if (check(binary)) {
		printf("Decimal number : %d\n", biToDec(binary));
	} else {
		printf("Invalid binary number.\n");
		return 1;
	}
	return 0;
}

int check (char binary[]) {
	int i, flag = 1;

	for (i = 0; i < 100; i++) {
		if (binary[i] != '1' &&
			binary[i] != '0' &&
			binary[i] != '\0') {
				flag = 0;
				break;
		}
		if (binary[i] == '\0') {
			break;
		}
	}

	return flag;
}

int biToDec (char binary[]) {
	int res = 0;
	int i;
	for (i = 0; i < 100; i++) {
		if (binary[i] == '1') {
			res *= 2;
			res += 1;
		} else if (binary[i] == '0')  {
			res *= 2;
		} else if (binary[i] == '\0') {
			break;
		}
	}

	return res;
}