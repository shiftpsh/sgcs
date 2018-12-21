
#include <stdio.h>

int main() {
	int a, b, c;
	int *pa, *pb, *pc;

	scanf("%d%d%d", &a, &b, &c);

	pa = &a; pb = &b; pc = &c;

	if (*pa >= *pb && *pb >= *pc) { // a >= b >= c
		printf("%d %d\n", *pc, *pa);
		printf("%p %p\n", pc, pa);
	} else if (*pa >= *pc && *pc >= *pb) { // a >= c >= b
                printf("%d %d\n", *pb, *pa);
                printf("%p %p\n", pb, pa);
        } else if (*pb >= *pa && *pa >= *pc) { // b >= a >= c
                printf("%d %d\n", *pc, *pb);
                printf("%p %p\n", pc, pb);
        } else if (*pb >= *pc && *pc >= *pa) { // b >= c >= a
                printf("%d %d\n", *pa, *pb);
                printf("%p %p\n", pa, pb);
        } else if (*pc >= *pa && *pa >= *pb) { // c >= a >= b
                printf("%d %d\n", *pb, *pc);
                printf("%p %p\n", pb, pc);
        } else if (*pc >= *pb && *pb >= *pa) { // c >= b >= a
                printf("%d %d\n", *pa, *pc);
                printf("%p %p\n", pa, pc);
        }
	return 0;
}
