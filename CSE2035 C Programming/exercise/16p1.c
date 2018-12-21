#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct __CUSTOMER__ {
	int number;
	char id[50];
	char pw[50];
	char name[50];
	char address[200];
} customer;

int main() {
	FILE* customers = fopen("customer.csv", "r");
	char buffer[500], *pch;
	customer* arr = (customer*)malloc(0);

	int i = 0, j = 0, size = 0;
	char reqid[50], reqpw[50];

	while (fgets(buffer, 500, customers)) {
		if (i == 0) {
			i++;
			continue;
		}

		size++;
		arr = (customer*)realloc(arr, size * sizeof(customer));
		j = 0;

		pch = strtok(buffer, ",");
		while (pch != NULL) {
			switch (j) {
			case 0:
				arr[size - 1].number = atoi(pch);
				break;
			case 1:
				strcpy(arr[size - 1].id, pch);
				break;
			case 2:
				strcpy(arr[size - 1].pw, pch);
				break;
			case 3:
				strcpy(arr[size - 1].name, pch);
				break;
			case 4:
				strcpy(arr[size - 1].address, pch);
				break;
			}
			pch = strtok(NULL, ",");
			j++;
		}

		i++;
	}

	fclose(customers);

	/* Login page */
	int user_id = -1;
	int login_try = 0;

	printf("로그인 프로그램\n");

	while (1) {
		printf("아이디: ");
		scanf("%s", &reqid);
		printf("비밀번호: ");
		scanf("%s", &reqpw);

		for (i = 0; i < size; i++) {
			if (strcmp(arr[i].id, reqid) == 0 && strcmp(arr[i].pw, reqpw) == 0) {
				user_id = i;
				break;
			}
		}

		if (user_id == -1) {
			login_try++;
			printf("일치하는 회원이 없습니다.\n");
			if (login_try == 3) break;
		}
		else {
			customer c = arr[user_id];
			printf("===================\n");
			printf("회원번호: %d\n", c.number);
			printf("아이디: %s\n", c.id);
			printf("비밀번호: %s\n", c.pw);
			printf("이름: %s\n", c.name);
			printf("주소: %s\n", c.address);
			break;
		}
	}

	free(arr);

	return 0;
}