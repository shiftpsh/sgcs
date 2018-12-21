#include <stdio.h>
#include <stdlib.h>

int* get_new_array(int);
void get_new_array_call_by_value(int*, int);
void get_new_array_call_by_reference(int**, int);
void print_state(int*);

int main() {
	int *a = NULL;
	print_state(a);

	get_new_array_call_by_value(a, 10);
	print_state(a);
	free(a);

        get_new_array_call_by_reference(&a, 10);
        print_state(a);
        free(a);

	a = get_new_array(10);
	print_state(a);
        free(a);

	return 0;
}

int* get_new_array(int size) {
	return (int*) malloc(size * sizeof(int));
}

void get_new_array_call_by_value(int* a, int size) {
	a = (int*) malloc(size * sizeof(int));

	/*
	*   This code does nothing to the pointer in main() scope
	*  because it sets the 'value' of 'local' variable a in
	*  this function scope, which has type of integer pointer,
	*  to the newly allocated array.
	*/
}

void get_new_array_call_by_reference(int** a, int size) {
        *a = (int*) malloc(size * sizeof(int));
}

void print_state(int* a) {
	if (a == NULL) {
		printf("not allocated\n");
	} else {
		printf("allocated\n");
	}
}

