#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

enum Date {
	Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday
};

struct Calendar {
	int year, month, day;
	enum Date date;
	char* dateString;
};

enum Date getDate(int, int, int);
char* getDay(enum Date);

int main() {
	int y, m, d;
	scanf("%d%d%d", &y, &m, &d);

	struct Calendar date = { y, m, d };
	date.date = getDate(date.year, date.month, date.day);
	date.dateString = getDay(date.date);

	printf("%s\n", date.dateString);

	return 0;
}

enum Date getDate(int y, int m, int d) {
	return (y + y / 4 - y / 100 + y / 400 + (13 * m + 8) / 5 + d) % 7;
}

char* getDay(enum Date currDate) {
	switch (currDate) {
	case Sunday:
		return "Sunday";
	case Monday:
		return "Monday";
	case Tuesday:
		return "Tuesday";
	case Wednesday:
		return "Wednesday";
	case Thursday:
		return "Thursday";
	case Friday:
		return "Friday";
	case Saturday:
		return "Saturday";
	default:
		break;
	}
}