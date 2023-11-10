#include "../inc/libmx.h"

unsigned long mx_hex_to_nbr(const char *hex)
{
    unsigned long result = 0;
    int i = 0;

    while(hex[i])
    {
        char symb = hex[i];

        if (symb >= '0' && symb <= '9')
        {
            result = result * 16 + (symb - '0');
        } else if (symb >= 'A' && symb <= 'F')
        {
            result = result * 16 + (symb - 'A' + 10);
        } else if (symb >= 'a' && symb <= 'f')
        {
            result = result * 16 + (symb - 'a' + 10);
        }

        i++;
    }

    return result;
}
