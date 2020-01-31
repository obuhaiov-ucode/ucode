#include "pathfinder.h"

static void print_distance(int *dijk, int *path, int last, int sum) {
    mx_printstr("\nDistance: ");
    if (last == 1)
        mx_printint(-dijk[path[last]]);
    else {
        sum = -dijk[path[1]];
        mx_printint(sum);
        for (int i = 2; i <= last; i++) {
            mx_printstr(" + ");
            mx_printint((-dijk[path[i]]) - sum);
            sum = ((-dijk[path[i]]) - sum) + sum;
        }
        mx_printstr(" = ");
        mx_printint(-dijk[path[last]]);
    }
}

static void print_path(char **names, int *dijk, int *path, int last) {
    mx_printstr("========================");
    mx_printstr("================\nPath: ");
    mx_printstr(names[path[0]]);
    mx_printstr(" -> ");
    mx_printstr(names[path[last]]);
    mx_printstr("\nRoute: ");
    for (int i = 0; i < last; i++) {
        mx_printstr(names[path[i]]);
        mx_printstr(" -> ");
    }
    mx_printstr(names[path[last]]);
    print_distance(dijk, path, last, 0);
    mx_printstr("\n====================");
    mx_printstr("====================\n");
}

static int not_dubl(int **pathes, int y, int last) {
    int x = 0;

    if (y == 0)
        return 1;
    for (; pathes[y - 1][x] >= 0 && pathes[y][x] >= 0
        && x <= last; x++) {
        if (pathes[y - 1][x] != pathes[y][x])
            return 1;
    }
    return 0;
}

static void print_one_isl(char **m, int **dijk, int **pathes, int n) {
    int first = pathes[0][0];
    int last = first + 1;

    for (; last <= n; last++) {
        for (int y = 0; pathes[y][0] >= 0; y++) {
            for (int x = 0; pathes[y][x] >= 0; x++) {
                if (pathes[y][x] == last
                    && (not_dubl(pathes, y, x)) == 1)
                    print_path(m, dijk[0], pathes[y], x);
            }
        }
    }
}

void mx_print_this_sht(char **names, int ***dijkstra, int ***pathes) {
    int n = mx_dia_len(dijkstra[0]);

    for (int isl = 0; isl < n; isl++)
        print_one_isl(names, dijkstra[isl], pathes[isl], n);
}
