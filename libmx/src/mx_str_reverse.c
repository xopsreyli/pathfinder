#include "../inc/libmx.h"

void mx_str_reverse(char *s)
{
    if (s) {
        int right = mx_strlen(s) - 1,
                left = 0;

        while (left < right) {
            mx_swap_char(&s[left], &s[right]);
            left++;
            right--;
        }
    }
}
