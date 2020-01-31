#include "pathfinder.h"

int *mx_first_fill(int *dijkstra, int *matrix, int isl) {
    for (int i = 0; matrix[i] != -2147483648; i++) {
        if (matrix[i] >= 0)
            dijkstra[i] = matrix[i];
    }
    dijkstra[isl] = -1;
    return dijkstra;
}
