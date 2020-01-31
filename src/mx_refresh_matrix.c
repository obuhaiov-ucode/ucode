#include "pathfinder.h"

static void sort_path(int ***dijkstra, int n) {
    int tmp = 0;

    for (int isl = 0; isl < n; isl++) {
        for (int j = 1; j < n; j++) {
            for (int i = 0; i <= n; i++) {
                if (dijkstra[isl][j][i] > dijkstra[isl][j + 1][i]
                    && dijkstra[isl][j + 1][i] > -1) {
                    tmp = dijkstra[isl][j][i];
                    dijkstra[isl][j][i] = dijkstra[isl][j + 1][i];
                    dijkstra[isl][j + 1][i] = tmp;
                }
            }
        }
    }
}

void mx_refresh_matrix(int ***dijkstra, int **matrix, int n) {
    sort_path(dijkstra, n);
    for (int j = 0; j < n; j++) {
        for (int i = 0; i <= n; i++) {
            if (-(dijkstra[j][0][i]) == matrix[j][i])
                dijkstra[j][0][i] *= -1;
            if (dijkstra[j][0][i] == -2147483648)
                dijkstra[j][0][i] = 0;
            if (dijkstra[j][n - 1][i] != 0)
                dijkstra[j][n][i]++;
            if (dijkstra[j][n][i] < 0)
                dijkstra[j][n][i] *= -1;
            if (dijkstra[j][n][i] == 0)
                dijkstra[j][n][i] = -1;
        }
    }
}
