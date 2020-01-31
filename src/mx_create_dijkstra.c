#include "pathfinder.h"

static int *malloc_first_row(int n, int isl, int first) {
    int *row = (int *)malloc(sizeof(int) * (n + 2));

    row[n + 1] = -2147483648;
    for (int i = 0; i <= n; i++) {
        if (first == 0)
            row[i] = 2147483647;
        else
            row[i] = -1;
    }
    row[isl] = -1;
    return row;
}

int ***mx_create_dijkstra(int n) {
    int ***dijkstra = (int ***)malloc(sizeof(int **) * (n + 1));
    int i = 0;

    for (int j = 0; j < n; j++) {
        dijkstra[j] = (int **)malloc(sizeof(int *) * (n + 2));
        for (i = 0; i <= n; i++) {
            dijkstra[j][i] = malloc_first_row(n, j, i);
        }
        dijkstra[j][n + 1] = 0;
    }
    dijkstra[n] = 0;
    return dijkstra;
}
