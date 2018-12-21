#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void show_memory(void) {
    FILE* status = fopen("/proc/self/status", "r");
    char buffer[256];
    while(fgets(buffer, sizeof(buffer) - 1, status)) {
        buffer[sizeof(buffer) -1] = '\0';
        if (strncmp(buffer, "VmSize:", 7) == 0)
            printf("memory:\t%d kb\n", atoi(buffer + 8));
    }
    fclose(status);
}


int main() {
	int* test;

	printf("*** Initial ***\n");
	printf("test:\t%p\n", test);
	printf("&test:\t%p\n", &test);
	show_memory();

	test = (int*) malloc(sizeof(int) * 100000);

        printf("*** malloc ***\n");
        printf("test:\t%p\n", test);
        printf("&test:\t%p\n", &test);
        printf("&test[0]:\t%p\n", &test[0]);
        show_memory();

	free(test);

        printf("*** free ***\n");
        printf("test:\t%p\n", test);
        printf("&test:\t%p\n", &test);
        printf("&test[0]:\t%p\n", &test[0]);
        show_memory();

	return 0;
}
