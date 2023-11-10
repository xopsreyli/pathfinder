#include "../inc/libmx.h"

void mx_printint(int n)
{
    if (n == -2147483648)
    {
        write(1, "-2147483648", 11);
    } else {
        if (0 > n)
        {
            n = -n;
            mx_printchar('-');
        }

        if (10 <= n)
        {
            mx_printint(n / 10);
        }

        char char_int = (n % 10) + '0';
        mx_printchar(char_int);
    }
}
