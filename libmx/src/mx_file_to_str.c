#include "../inc/libmx.h"

char *mx_file_to_str(const char *file)
{
    int fd = open(file, O_RDONLY);

    if (fd == -1) {
        return NULL;
    }

    char c;
    int length = 0;
    int read_result = read(fd, &c, 1);

    while (read_result != 0) {
        read_result = read(fd, &c, 1);
        length++;
    }

    close(fd);

    char *result = mx_strnew(length);
    fd = open(file, O_RDONLY);
    read(fd, result, length);
    close(fd);

    return result;
}
