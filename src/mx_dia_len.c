#include "pathfinder.h"

int mx_dia_len(int **matrix) {
    int i = 0;

    while (matrix[i]) {
        if (matrix[i+1] == 0)
            return i;
        i++;
    }
    return -1;
}
