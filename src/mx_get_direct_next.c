#include "pathfinder.h"

int mx_get_direct_next(int *dijkstra, int n) {
    for (int i = 0; i <= n; i++) {
        if (dijkstra[i] > 0) {
            dijkstra[i] *= -1;
            return i;
        }
        if (dijkstra[i] == 0) {
            dijkstra[i] = -2147483648;
            return i;
        }
    }
    return -1;
}
