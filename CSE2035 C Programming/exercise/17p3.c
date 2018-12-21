#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct __SUBJECT__ {
	char number[8];
	int credit;
	double grade;
}subject;

typedef struct __STUDENT__ {
	int id;
	int number_of_course;
	subject *courses;
}student;

double calcCGPA(student);

int main() {
	int n, i, j, id, m;

	scanf("%d", &n);
	student* arr = (student*)malloc(sizeof(student) * n);

	for (i = 0; i < n; i++) {
		scanf("%d%d", &id, &m);

		arr[i].id = id;
		arr[i].number_of_course = m;
		arr[i].courses = (subject*)malloc(sizeof(subject) * m);

		for (j = 0; j < m; j++) {
			scanf("%s%d%lf",
				&(arr[i].courses[j].number),
				&(arr[i].courses[j].credit),
				&(arr[i].courses[j].grade)
			);
		}
	}

	printf("==========\n");

	for (i = 0; i < n; i++) {
		printf("%d / %lf\n", arr[i].id, calcCGPA(arr[i]));
	}

	for (i = 0; i < n; i++) {
		free(arr[i].courses);
	}
	free(arr);
	
	return 0;
}

double calcCGPA(student s) {
	int csum = 0, i;
	double gsum = 0;

	for (i = 0; i < s.number_of_course; i++) {
		csum += s.courses[i].credit;
		gsum += s.courses[i].grade * s.courses[i].credit;
	}

	if (csum == 0) return 0.0;
	else return gsum / csum;
}