//
// Created by Suhyun Park on 2018-12-04.
//

#ifndef CP_PROJECT_UTIL_IO_H
#define CP_PROJECT_UTIL_IO_H

void scan_valid_id(char *temp, char *error_message, char *retry_message);

void scan_valid_string(char *temp, char *error_message, char *retry_message);

int scan_valid_boolean(char *error_message, char *retry_message);

int scan_valid_int(int min, int max, char *error_message, char *retry_message);

#endif //CP_PROJECT_UTIL_IO_H
