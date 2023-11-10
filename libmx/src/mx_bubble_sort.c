#include "../inc/libmx.h"

int mx_bubble_sort(char **arr, int size)
{
    int swaps = 0;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            int diff = mx_strcmp(arr[i], arr[j]);
            if (0 < diff)
            {
                char *temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                swaps++;
            }
        }
    }

    return swaps;
}
