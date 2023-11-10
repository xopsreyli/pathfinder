#include "../inc/libmx.h"

double mx_pow(double n, unsigned int pow)
{
    double result = 1;

    if (0 == pow)
    {
        return result;
    }

    for (unsigned int i = 0; i < pow; i++) {
        result *= n;
    }

    return result;
}
