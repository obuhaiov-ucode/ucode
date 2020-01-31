#include "pathfinder.h"

int mx_nex_dubl(int **dijk, int prev, int closed, int n) {
    int x = closed + 1;

    for (int y = 1; x <= n;) {
        y = 1;
        for (; dijk[y][x] < 0 && x <= n && x != closed; x++);
        for (; dijk[y][x] != prev && dijk[y][x] >= 0 && y < n; y++);
        if (dijk[y][x] < 0) {
            y = 1;
            x++;
        }
        if (dijk[y][x] == prev && x <= n && y < n && x != closed)
            return x;
    }
    return -1;
}
