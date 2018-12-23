#ifndef UTIL_STRING_H
#define UTIL_STRING_H

/// Macro to fix fgets getting newline character (\n) after using scanf
#define CLEAR_INPUT_BUFFER int __x; \
                    while((__x = getchar()) != '\n' && __x != EOF);

void string_itoa(char *str, int value);

void string_to_lowercase(char *str);

void string_to_uppercase(char *str);

int string_invalid(char *str);

int string_id_invalid(char *str);

char *string_trim(char *str);

void string_mask(char *str, char c);

#endif