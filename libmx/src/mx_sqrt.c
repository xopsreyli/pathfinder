#include "../inc/libmx.h"

int mx_sqrt(int x)
{
    if (0 == x || 1 == x) {
        return x;
    }

    int left = 1, right = x;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (mid * mid == x) {
            return mid;
        }

        if (mid < x / mid) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return 0;
}
