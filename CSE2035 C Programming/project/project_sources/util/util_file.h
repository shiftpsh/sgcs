#ifndef UTIL_FILE_H
#define UTIL_FILE_H

int file_exists(char *filename);

void file_write(char *filename, char *contents);

void file_writeln(char *filename, char *contents);

#endif