#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "util_file.h"

/*
	=====
	File - related helper functions
	=====
*/

/// Check if specific file exists by filename.
/// May behave strange when file permission changed manually;
/// \param filename Name of the file
/// \return 1 if file exists; 0 otherwise
int file_exists(char *filename) {
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL) return 0;
    fclose(fptr);
    return 1;
}

/// Initialize a file by writing some content to it.
/// \param filename Name of the file
/// \param contents Contents to write
void file_write(char *filename, char *contents) {
    FILE *fptr = fopen(filename, "w");
    fputs(contents, fptr);
    fclose(fptr);
}

/// Initialize a file by writing some content to it, and append newline(\n).
/// \param filename Name of the file
/// \param contents Contents to write
void file_writeln(char *filename, char *contents) {
    FILE *fptr = fopen(filename, "w");
    fputs(contents, fptr);
    fputs("\n", fptr);
    fclose(fptr);
}