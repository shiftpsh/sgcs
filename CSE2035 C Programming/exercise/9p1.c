#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int string_length(char*);

int main() {
	char s[] = "C is a high-level language";
	char *t = "C프로그래밍";

	printf("Length of s : %d\n", string_length(s));
	/*	= 26
		: length of string s.
	*/

	printf("sizeof(s)   : %d\n", (int) sizeof(s));
	/*	= 27
		: size of array s, which is 1 longer than
		  the length of string s because of the 
		  delimiter '\0'.
	*/

	printf("Length of t : %d\n", string_length(t));
	/*	= 11
		: length of string t, when hangul characters
		  treated as 2-bytes.
	*/

	printf("sizeof(t)   : %d\n", (int) sizeof(t));
	/*	= 4
		: size of pointer t.
	*/

	return 0;
}

int string_length(char *st) {
	int i = 0;

	while (st[i] != '\0') i++;

	return i;
}