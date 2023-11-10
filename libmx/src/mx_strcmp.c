#include "../inc/libmx.h"

int mx_strcmp(const char *s1, const char *s2)
{
    int i = 0;
    while(s1[i] || s2[i])
    {
        if (s1[i] != s2[i])
        {
            return (int)s1[i] - (int)s2[i];
        }
        i++;
    }

    return 0;
}
