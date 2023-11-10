#include "../inc/libmx.h"

char *mx_strstr(const char *haystack, const char *needle)
{
    for (int i = 0; haystack[i]; i++) {
        if (haystack[i] == needle[0]) {
            int j = 0,
                clone_i = i;
            while (haystack[clone_i] == needle[j]) {
                clone_i++;
                j++;
            }
            if (!needle[j]) {
                return (char *)&haystack[i];
            }
        }
    }

    return NULL;
}
