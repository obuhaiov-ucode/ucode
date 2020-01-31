#include "pathfinder.h"

void mx_del_matrix(int **arr) {
    for (unsigned int i = 0; arr[i] != NULL; i++) {
        free(arr[i]);
        arr[i] = NULL;
    }
    free(arr);
    arr = NULL;
}
