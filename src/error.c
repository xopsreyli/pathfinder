#include "../inc/pathfinder.h"

void throw_error(const char* error) {
    mx_printstr(error);
    mx_printchar('\n');

    exit(1);
}

void file_not_exist(char* filename) {
    mx_printstr("error: file ");
    mx_printstr(filename);
    mx_printstr(" does not exist");
    mx_printchar('\n');

    exit(1);
}

void file_is_empty(char* filename) {
    mx_printstr("error: file ");
    mx_printstr(filename);
    mx_printstr(" is empty");
    mx_printchar('\n');

    exit(1);
}

void invalid_line_error(int line_number) {
    mx_printstr("error: line ");
    mx_printint(line_number);
    mx_printstr(" is not valid");
    mx_printchar('\n');

    exit(1);
}
