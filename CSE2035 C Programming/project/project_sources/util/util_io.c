//
// Created by Suhyun Park on 2018-12-04.
//

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include "util_io.h"
#include "util_string.h"

/// Scan a valid id.
/// \param [out] temp Scanned string
/// \param error_message Error message to print when scanned id is invalid
/// \param retry_message Retry message to print when scanned id is invalid
void scan_valid_id(char *temp, char *error_message, char *retry_message) {
    do {
        fgets(temp, 1000, stdin);
        temp[strlen(temp) - 1] = '\0';
        if (string_id_invalid(temp)) {
            printf(error_message);
            printf(retry_message);
        }
    } while (string_id_invalid(temp));
}


/// Scan a valid csv cell.
/// \param [out] temp Scanned string
/// \param error_message Error message to print when scanned string is invalid
/// \param retry_message Retry message to print when scanned string is invalid
void scan_valid_string(char *temp, char *error_message, char *retry_message) {
    do {
        fgets(temp, 1000, stdin);
        temp[strlen(temp) - 1] = '\0';
        if (string_invalid(temp)) {
            printf(error_message);
            printf(retry_message);
        }
    } while (string_invalid(temp));
}


/// Scan a valid boolean value.
/// \param error_message Error message to print when scanned string is invalid
/// \param retry_message Retry message to print when scanned string is invalid
/// \return 1 if scanned string is y, 1, true, or yes; 0 if scanned string is n, 0, false or no.
int scan_valid_boolean(char *error_message, char *retry_message) {
    char temp[101];

    do {
        scanf("%s", temp);
        string_to_lowercase(temp);

        if (strcmp(temp, "y") == 0) return 1;
        if (strcmp(temp, "1") == 0) return 1;
        if (strcmp(temp, "true") == 0) return 1;
        if (strcmp(temp, "yes") == 0) return 1;

        if (strcmp(temp, "n") == 0) return 0;
        if (strcmp(temp, "0") == 0) return 0;
        if (strcmp(temp, "false") == 0) return 0;
        if (strcmp(temp, "no") == 0) return 0;

        printf(error_message);
        printf(retry_message);
    } while (1);
}

/// Scan a valid integer value.
/// \param min Minimum value
/// \param max Maximum value
/// \param error_message Error message to print when scanned string is invalid
/// \param retry_message Retry message to print when scanned string is invalid
/// \return Scanned integer value
int scan_valid_int(int min, int max, char *error_message, char *retry_message) {
    char temp[18];
    long long v;

    do {
        scanf("%s", temp);
        v = atoll(temp);

        if (min <= v && v <= max) {
            return (int) v;
        }

        printf(error_message);
        printf(retry_message);
    } while (1);
}