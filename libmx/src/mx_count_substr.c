#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub)
{
    if (!str || !sub) {
        return -1;
    } else if ('\0' == sub[0]) {
        return 0;
    }

    int count = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == sub[0]) {
            int j = 0,
                clone_i = i;
            while (str[clone_i] == sub[j] && sub[j]) {
                clone_i++;
                j++;
            }
            if (!sub[j]) {
                count++;
            }
        }
    }

    return count;
}
