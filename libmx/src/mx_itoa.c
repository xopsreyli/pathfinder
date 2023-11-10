#include "../inc/libmx.h"

char *mx_itoa(int number)
{
    if (-2147483648 == number) {
        return "-2147483648";
    } else if (0 == number) {
        return "0";
    }

    int copy = number,
        counter = 0;

    while (copy > 0) {
        copy /= 10;
        counter++;
    }

    char *result = mx_strnew(counter + 1);
    result[counter] = '\0';

    while (number > 0) {
        int remainder = number % 10;
        result[counter - 1] = remainder + '0';
        counter--;
        number /= 10;
    }

    return result;
}
