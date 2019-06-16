#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 101

int pi[MAX_LENGTH];

int construct_pi(char *pat) {
    int j = 0;
    int counter = 0;
    int pat_length = strlen(pat);

    for (int i = 1; i < pat_length; i++) {
        counter++;
        while (j > 0 && pat[i] != pat[j]) {
            j = pi[j - 1];
            counter++;
        }
        if (pat[i] == pat[j]) {
            pi[i] = ++j;
        }
    }

    return counter;
}

int kmp(char *str, char *pat) {
    int counter = construct_pi(pat);
    int str_length = strlen(str);
    int pat_length = strlen(pat);

    int j = 0;

    for (int i = 0; i < str_length; i++) {
        counter++;
        while (j > 0 && str[i] != pat[j]) {
            counter++;
            j = pi[j - 1];
        }
        if (str[i] == pat[j]) {
            if (j == pat_length - 1) {
                return counter;
            } else {
                j++;
            }
        }
    }

    return -counter;
}

int nfind(char *str, char *pat) {
    int counter = 0;
    int str_length = strlen(str);
    int pat_length = strlen(pat);

    int i, j, start = 0;

    int endmatch = pat_length - 1;

    for (i = 0; endmatch < str_length; endmatch++, start++) {
        counter++;
        if (str[endmatch] == pat[pat_length - 1]) {
            j = 0;
            i = start;
            while (j < pat_length - 1 && str[i] == pat[j]) {
                counter++;
                i++;
                j++;
            }
        }
        if (j == pat_length - 1) {
            return counter;
        }
    }

    return -counter;
}

int main() {
    char str[MAX_LENGTH], pat[MAX_LENGTH];

    fgets(str, MAX_LENGTH, stdin);
    str[strlen(str) - 1] = '\0';

    fgets(pat, MAX_LENGTH, stdin);
    pat[strlen(pat) - 1] = '\0';

    int nfind_result = nfind(str, pat);
    int kmp_result = kmp(str, pat);

    if (nfind_result > 0) {
        printf("nfind:    YES %5d\n", nfind_result);
    } else {
        printf("nfind:    NO  %5d\n", -nfind_result);
    }

    if (kmp_result > 0) {
        printf("kmp:      YES %5d\n", kmp_result);
    } else {
        printf("kmp:      NO  %5d\n", -kmp_result);
    }

    return 0;
}