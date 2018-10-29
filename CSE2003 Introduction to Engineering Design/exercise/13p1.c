#include <stdio.h>

int main(void) {
    float f;

    printf("Input : ");
    scanf("%f", &f);

    // round(f) =   (int) (f + 0.5)
    // floor(f) =   (int)  f

    // if round(f) > floor(f):
    printf("Use \">\"  : %d\n", (int)(f + 0.5)          >  (int)f       );

    // if round(f) - floor(f) >= 1:
    printf("Use \">=\" : %d\n", (int)(f + 0.5) - (int)f >= 1            );

    // if round(f) - floor(f) == 1:
    printf("Use \"==\" : %d\n", (int)(f + 0.5) - (int)f == 1            );

    // if round(f) != floor(f):
    printf("Use \"!=\" : %d\n", (int)(f + 0.5)          != (int)f       );

    return 0;
}
