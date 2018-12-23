#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "util_string.h"

/*
	=====
	String - related helper functions
	=====
*/

/// Converts an int to string.
/// \param [out] str String to be overwritten
/// \param value Integer to convert
void string_itoa(char *str, int value) {
    char *ptr = str;

    if (value < 0) {
        *ptr = '-';
        ptr++;
        value *= -1;
    }

    int pow = value;
    do {
        ptr++;
        pow /= 10;
    } while (pow);

    *ptr = '\0';
    do {
        ptr--;
        *ptr = (char) (value % 10 + '0');
        value /= 10;
    } while (value > 0);
}

/// Makes string to lowercase.
/// \param [out] str String to be transformed to lowercase
void string_to_lowercase(char *str) {
    int l = (int) strlen(str);

    for (int i = 0; i < l; i++) {
        if ('A' <= str[i] && str[i] <= 'Z') str[i] += 0x20;
    }
}

/// Makes string to uppercase.
/// \param [out] str String to be transformed to uppercase
void string_to_uppercase(char *str) {
    int l = (int) strlen(str);

    for (int i = 0; i < l; i++) {
        if ('a' <= str[i] && str[i] <= 'z') str[i] -= 0x20;
    }
}

/// Check if given string is a valid csv cell.
/// \param str String to check
/// \return 1 if str does not contain quotes(") or commas(,); 0 otherwise
int string_invalid(char *str) {
    int i = 0;

    if (strlen(str) == 0) return 1;

    while (str[i] != '\0') {
        if (str[i] == '"') return 1;
        if (str[i] == ',') return 1;
        i++;
    }

    return 0;
};

/// Check if given string is a valid id.
/// \param str String to check
/// \return 1 if str is only composed of numbers, uppercase and
/// lowercase letters, underscore(_), and its length is between 4 and 16; 0 otherwise
int string_id_invalid(char *str) {
    int i = 0;

    if (strlen(str) < 4) return 1;
    if (strlen(str) > 16) return 1;

    while (str[i] != '\0') {
        if (!(('a' <= str[i] && str[i] <= 'z') ||
              ('A' <= str[i] && str[i] <= 'Z') ||
              ('0' <= str[i] && str[i] <= '9') ||
              (str[i] == '_')))
            return 1;
        i++;
    }

    return 0;
};

/// Trim leading/trailing whitespaces and newlines from string.
/// \param [out] str String to be trimmed.
/// \return Pointer of the trimmed string.
char *string_trim(char *str) {
    char *end;

    // Trim leading space
    while (isspace((unsigned char) *str)) str++;

    if (*str == 0) return str;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char) *end)) end--;

    end[1] = '\0';

    return str;
}

/// Mask a string with given character.
/// \param [out] str String to be masked
/// \param c Character to use with masking
void string_mask(char *str, char c) {
    int l = (int) strlen(str);

    for (int i = 0; i < l; i++) {
        str[i] = c;
    }
}