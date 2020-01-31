#include "pathfinder.h"

static int *get_row(int **dijk, int **arr, int next, int num_row) {
    int n = mx_dia_len(dijk);
    int first = mx_get_first(dijk, n);
    int i = 0;

    arr[num_row] = (int *)malloc(sizeof(int) * (n + 2));
    arr[num_row][i++] = first;
    arr[num_row][i++] = next;
    for (; next >= 0;) {
        next = mx_get_next(dijk, next, n);
        arr[num_row][i++] = next;
    }
    return arr[num_row];
}

static int *copy_row(int **dijkstra, int *arr, int next, int ind) {
    int n = mx_dia_len(dijkstra);
    int *row = (int *)malloc(sizeof(int) * (n + 1));
    int i = 0;

    for (; i < ind; i++)
        row[i] = arr[i];
    row[ind++] = next;
    for (; next >= 0;) {
        next = mx_get_next(dijkstra, next, n);
        row[ind++] = next;
    }
    return row;
}

static int get_index(int **dijk, int **arr, int r, int n) {
    int i = 0;

    for (; arr[r][i] >= 0; i++);
    for (;((mx_nex_dubl(dijk, arr[r][i - 2], arr[r][i - 1], n)) < 0)
        && i > 1; i--);
    if ((mx_nex_dubl(dijk, arr[r][i - 2], arr[r][i - 1], n)) >= 0)
        return i - 1;
    return -1;
}

static int **get_arr(int **dijk, int ind, int next, int n) {
    int **arr = (int **)malloc(sizeof(int *) * (((n - 1) * n) + 1));
    int i = 0;
    int next_dubl = -1;

    arr[((n - 1) * n)] = 0;
    next = mx_get_direct_next(dijk[0], n);
    for (; next >= 0;) {
        arr[i] = get_row(dijk, arr, next, i);
        i++;
        for (; (next_dubl = mx_any_dubl(dijk, arr, i - 1, n)) != -1
            && (ind = get_index(dijk, arr, i - 1, n)) != 0;) {
            arr[i] = copy_row(dijk, arr[i - 1], next_dubl, ind);
            i++;
        }
        next = mx_get_direct_next(dijk[0], n);
    }
    arr[i] = (int *)malloc(sizeof(int) * 1);
    arr[i][0] = -1;
    return arr;
}

int ***mx_fill_pathes(int ***dijkstra) {
    int n = mx_dia_len(dijkstra[0]);
    int ***pathes = (int ***)malloc(sizeof(int **) * (n + 1));

    pathes[n] = 0;
    for (int isl = 0; isl < n; isl++)
        pathes[isl] = get_arr(dijkstra[isl], 0, 0, n);
    mx_refresh_dijkstra(dijkstra, n);
    return pathes;
}
