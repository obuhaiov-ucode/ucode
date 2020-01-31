#include "pathfinder.h"

void mx_hardkostuling(char **names, int *path) {
    mx_printstr("========================");
    mx_printstr("================\nPath: ");
    mx_printstr(names[0]);
    mx_printstr(" -> ");
    mx_printstr(names[1]);
    mx_printstr("\nRoute: ");
    mx_printstr(names[0]);
    mx_printstr(" -> ");
    mx_printstr(names[1]);
    mx_printstr("\nDistance: ");
    mx_printint(path[3]);
    mx_printstr("\n====================");
    mx_printstr("====================\n");
    free(path);
    mx_del_strarr(&names);
}
