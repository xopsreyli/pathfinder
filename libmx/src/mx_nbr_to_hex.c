#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr)
{
    char *symbs = "0123456789abcdef";
    int reminders[20],
        counter = 0;

    while(nbr > 15) {
        int reminder = nbr % 16;
        reminders[counter] = reminder;
        counter++;
        nbr /= 16;
    }

    reminders[counter] = nbr;
    char *result = mx_strnew(counter + 2);
    int j = counter,
        i = 0;

    for (; i <= counter; i++) {
        result[i] = symbs[reminders[j--]];
    }
    result[i] = '\0';

    return result;
}
