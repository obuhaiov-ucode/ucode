#include "pathfinder.h"

static int smallest_index(int *dijkstra, int n) {
    int smallest = 2147483647;
    int x = 0;

    for (; x <= n; x++) {
        if (dijkstra[x] < smallest && dijkstra[x] >= 0)
            smallest = dijkstra[x];
    }
    for (x = 0; x <= n; x++) {
        if (dijkstra[x] == smallest)
            return x;
    }
    return -1;
}

static void put_path(int **dijkstra, int n, int x, int smallest) {
    int i = 1;

    while (i <= n) {
        if (dijkstra[i][x] == -1) {
            dijkstra[i][x] = smallest;
            break;
        }
        i++;
    }
}

static void refresh(int **dijkstra, int n, int x) {
    int i = 1;

    while (i <= n) {
        dijkstra[i][x] = -1;
        i++;
    }
}

static int *cycle(int **dijkstra, int **matrix, int s, int n) {
    for (int isl = 0; isl < n; isl++) {
        s = smallest_index(dijkstra[0], n);
        for (int x = 0; x <= n; x++) {
            if (dijkstra[0][x] > dijkstra[0][s] + matrix[s][x]
                && dijkstra[0][x] > 0 && matrix[s][x] > 0)
                refresh(dijkstra, n, x);
            if (dijkstra[0][x] >= dijkstra[0][s] + matrix[s][x]
                && dijkstra[0][x] >= 0 && matrix[s][x] >= 0) {
                dijkstra[0][x] = dijkstra[0][s] + matrix[s][x];
                put_path(dijkstra, n, x, s);
            }
        }
        if (dijkstra[0][s] == 0)
            dijkstra[0][s] = -2147483648;
        else
            dijkstra[0][s] = -dijkstra[0][s];
    }
    return dijkstra[0];
}

int ***mx_dijkstra(int **matrix) {
    int n = mx_dia_len(matrix);
    int ***dijk = mx_create_dijkstra(n);
    int isl = 0;

    for (; isl < n; isl++) {
        dijk[isl][0] = mx_first_fill(dijk[isl][0], matrix[isl], isl);
        dijk[isl][0] = cycle(dijk[isl], matrix, 0, n);
        dijk[isl][n][isl] = 0;
    }
    mx_refresh_matrix(dijk, matrix, n);
    return dijk;
}
