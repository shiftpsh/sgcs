#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char dept_name[25];
	int dept_no;
} dept;

enum Gender {Male = 0, Female};

typedef struct {
	int employee_id;
	char name[25];
	enum Gender gender;
	dept department;
	double salary;
}employee_data;

int search(employee_data*, int, int);
employee_data update(employee_data, int);
void print_employee(employee_data);

int main() {
	FILE* data = fopen("input.csv", "r");
	char buffer[500], *token;
	int n, i = 0, x, idx, d;
	char flow;

	fgets(buffer, 500, data);
	n = atoi(buffer);

	employee_data* arr = (employee_data*)malloc(n * sizeof(employee_data));

	while (fgets(buffer, 500, data)) {
		token = strtok(buffer, ",");
		arr[i].employee_id = atoi(token);

		token = strtok(NULL, ",");
		strcpy(arr[i].name, token);

		token = strtok(NULL, ",");
		if (strcmp(token, "Female") == 0) {
			arr[i].gender = Female;
		}
		else {
			arr[i].gender = Male;
		}

		token = strtok(NULL, ",");
		strcpy(arr[i].department.dept_name, token);

		token = strtok(NULL, ",");
		arr[i].department.dept_no = atoi(token);

		token = strtok(NULL, ",");
		arr[i].salary = atoi(token);

		i++;
	}

	fclose(data);

	while (1) {
		printf("Employee ID : ");
		scanf("%d", &x);

		idx = search(arr, n, x);
		if (idx == -1) {
			printf("No Employee\n");
			printf("Continue? (y/n) : ");
			scanf("\n%c", &flow);
			if (flow == 'n') break;
			continue;
		}

		printf("------Employee Data------\n");
		print_employee(arr[idx]);

		printf("------Update Information------\n");
		printf("Input the department number : ");
		scanf("%d", &d);
		arr[idx] = update(arr[idx], d);

		printf("------Updated Employee Data------\n");
		print_employee(arr[idx]);

		printf("Continue? (y/n) : ");
		scanf("\n%c", &flow);
		if (flow == 'n') break;
	}

	free(arr);

	return 0;
}

int search(employee_data *e, int num, int keyword) {
	int i = 0;

	for (i = 0; i < num; i++) {
		if (e[i].employee_id == keyword) return i;
	}

	return -1;
}

employee_data update(employee_data e, int n) {
	e.department.dept_no = n;

	switch (e.department.dept_no) {
	case 1:
		strcpy(e.department.dept_name, "FINANCE");
		break;
	case 2:
		strcpy(e.department.dept_name, "SALES");
		break;
	case 3:
		strcpy(e.department.dept_name, "RESEARCH");
		break;
	case 4:
		strcpy(e.department.dept_name, "PLANNING");
		break;
	}

	return e;
}

void print_employee(employee_data e) {
	if (e.gender == Female) {
		printf("%d / %s / Female / %s / %d / %.2lf\n",
			e.employee_id,
			e.name,
			e.department.dept_name,
			e.department.dept_no,
			e.salary
		);
	}
	else {
		printf("%d / %s / Male / %s / %d / %.2lf\n",
			e.employee_id,
			e.name,
			e.department.dept_name,
			e.department.dept_no,
			e.salary
		);
	}
}