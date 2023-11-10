#include "../inc/libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count)
{
    int left = 0, right = size - 1;

    while (left <= right)
    {
        (*count)++;

        int mid = left + (right - left) / 2,
                comparison = mx_strcmp(arr[mid], s);

        if (0 == comparison)
        {
            return mid;
        }

        if (comparison < 0)
        {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    *count = 0;

    return -1;
}
