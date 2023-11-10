#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub)
{
    if (!str || !sub) {
        return -2;
    }

    int str_len = mx_strlen(str);
    int sub_len = mx_strlen(sub);

    for (int i = 0; i <= str_len - sub_len; i++) {
        if (str[i] == sub[0]) {
            int j = 0;
            while (str[i + j] == sub[j]) {
                j++;
                if (j == sub_len) {
                    return i;
                }
            }
        }
    }

    return -1;
}
