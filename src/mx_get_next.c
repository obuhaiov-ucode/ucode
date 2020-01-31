#include "pathfinder.h"

int mx_get_next(int **dijk, int prev, int n) {
    int x = 0;

    for (int y = 1; x <= n && prev >= 0;) {
        y = 1;
        for (; dijk[y][x] < 0 && x <= n; x++);
        for (; dijk[y][x] != prev && dijk[y][x] >= 0 && y < n; y++);
        if (dijk[y][x] < 0) {
            y = 1;
            x++;
        }
        if (dijk[y][x] == prev && x <= n && y < n)
            return x;
    }
    return -1;
}
