#include "pathfinder.h"

static int count_islands(char **split) {
    int i;

    i = 0;
    while (split[i] != 0) {
        i++;
    }
    return i;
}

static int num_isl(char *s) {
    int i = 0;
    int n = 1;
    int r = 0;

    while (s[i] != '\0')
        i++;
    i--;
    while (i >= 0) {
        r = r + (s[i] - '0') * n;
        n = n * 10;
        i--;
    }
    return r;
}

static int get_isl_ind(char **islands_names, char *tmp) {
    int i;

    i = 0;
    while (islands_names[i] != 0) {
        if (mx_strcmp(islands_names[i], tmp) == 0)
            return i * -1;
        i++;
    }
    return -2147483648;
}

static int *islands_as_index(char **islands_names, char **split) {
    int n = count_islands(split);
    int *isl_ind = (int *)malloc(sizeof(int) * (n + 1));
    int i;

    i = 0;
    isl_ind[n] = -2147483648;
    while (split[i]) {
        if (i % 3 == 0)
            isl_ind[i] = num_isl(split[i]);
        else
            isl_ind[i] = get_isl_ind(islands_names, split[i]);
        i++;
    }
    if (isl_ind[0] == 2) {
        mx_del_strarr(&split);
        mx_hardkostuling(islands_names, isl_ind);
        exit(0);
    }
    return isl_ind;
}

int **mx_islands_matrix(char **names, char **split, int y, int x) {
    int *isl_index = islands_as_index(names, split);
    int **isl_matrix = mx_matrix_empty(isl_index);
    int i = 1;

    while (isl_index[i] != -2147483648) {
        y = isl_index[i] * -1;
        x = isl_index[i + 1] * -1; 
        isl_matrix[y][x] = isl_index[i + 2];
        isl_matrix[x][y] = isl_index[i + 2];
        i = i + 3;
    }
    mx_del_strarr(&split);
    free(isl_index);
    return isl_matrix;
}
