#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strCmpPk(char* s1, char* s2);
void strPk(char* s1, char* s2);

int main() {
    char s1[101], s2[101];

    printf("first string  : ");
    scanf("%s", s1);
    printf("second string : ");
    scanf("%s", s2);

    int x = strCmpPk(s1, s2);
    if (x == 0) {
        printf("string1 == string2\n");
    }
    else if (x < 0) {
        printf("string1 < string2\n");
    }
    else {
        printf("string1 > string2\n");
    }

    return 0;
}

int strCmpPk(char* s1, char* s2) {
    strPk(s1, s2);
    return strcmp(s1, s2);
}

void strPk(char* s1, char* s2) {
    int l1 = strlen(s1), l2 = strlen(s2);
    int i1 = 0, i2 = 0, j1 = 0, j2 = 0;

    char* t1 = (char*)malloc(sizeof(char) * (l1 + 1));
    char* t2 = (char*)malloc(sizeof(char) * (l2 + 1));

    for (i1 = 0; i1 < l1; i1++) {
        if ('a' <= s1[i1] && s1[i1] <= 'z'
            || 'A' <= s1[i1] && s1[i1] <= 'Z') {
            t1[j1] = s1[i1];
            j1++;
        }
    }
    t1[j1] = '\0';

    for (i2 = 0; i2 < l2; i2++) {
        if ('a' <= s2[i2] && s2[i2] <= 'z'
            || 'A' <= s2[i2] && s2[i2] <= 'Z') {
            t2[j2] = s2[i2];
            j2++;
        }
    }
    t2[j2] = '\0';

    strcpy(s1, t1);
    strcpy(s2, t2);
    free(t1);
    free(t2);
}