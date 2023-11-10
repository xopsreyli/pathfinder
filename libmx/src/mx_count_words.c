#include "../inc/libmx.h"

int mx_count_words(const char *str, char c)
{
    if (!str) {
        return -1;
    }

    int count = 0;
    bool flag = false;

    for (int i = 0; str[i]; i++) {
        if (str[i] == c) {
            flag = false;
        } else {
            if (!flag) {
                flag = true;
                count++;
            }
        }
    }

    return count;
}
