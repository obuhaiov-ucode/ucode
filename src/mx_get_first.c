#include "pathfinder.h"

int mx_get_first(int **dijk, int n) {
    for (int i = 0; i <= n; i++) {
        if (dijk[0][i] == -1 && dijk[1][i] == -1 && dijk[n][i] == 1)
            return i;
    }
    return -1;
}
