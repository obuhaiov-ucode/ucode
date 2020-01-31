#include "pathfinder.h"

int **mx_matrix_empty(int *isl_index) {
    int n = isl_index[0];
    int **islands_matrix = (int **)malloc(sizeof(int *) * (n + 1));
    int i;
    int j;

    i = 0;
    islands_matrix[n] = 0;
    while (i < n) {
        j = 0;
        islands_matrix[i] = (int *)malloc(sizeof(int) * (n + 1));
        for (; j < n; j++)
            islands_matrix[i][j] = -1;
        islands_matrix[i][j] = -2147483648;
        i++;
    }
    for (i = 0; n > 0; i++, n--)
        islands_matrix[i][i] = -(i + 1);
    return islands_matrix;
}
