#include "pathfinder.h"

int mx_any_dubl(int **dijk, int **arr, int r, int n) {
    int i = 0;

    for (; arr[r][i] >= 0; i++);
    for (;((mx_nex_dubl(dijk, arr[r][i - 2], arr[r][i - 1], n)) < 0)
        && i > 1; i--);
    if ((mx_nex_dubl(dijk, arr[r][i - 2], arr[r][i - 1], n)) >= 0)
        return mx_nex_dubl(dijk, arr[r][i - 2], arr[r][i - 1], n);
    return -1;
}
