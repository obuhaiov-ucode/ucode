#include "pathfinder.h"

int main(int c, char **v) {
    if (c == 2) {
        c = mx_valid(v[1]);
        if (c == 0) {
            char **split = mx_isl_to_str(v[1]);
            char **names = mx_island_as_unistring(split);
            int **matrix = mx_islands_matrix(names, split, 0, 0);
            int ***dijkstra = mx_dijkstra(matrix);
            int ***pathes = mx_fill_pathes(dijkstra);

            mx_print_this_sht(names, dijkstra, pathes);
            return 0;
        }
        mx_print_err(c, v[1]);
        return 1;
    }
    write(2, "usage: ./pathfinder [filename]\n", 31);
    return 1;
}
