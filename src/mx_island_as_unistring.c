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

static int strcmp_newisland(char **res, char *s) {
    int i;

    i = 0;
    if (s[i] >= '0' && s[i] <= '9')
        return 1;
    while (res[i] != 0) {
        if (mx_strcmp(res[i], s) == 0)
            return 1;
        i++;
    }
    return 0;
}

char **mx_island_as_unistring(char **split) {
    int n = num_isl(split[0]);
    int num = count_islands(split);
    char **res = (char **)malloc(sizeof(char *) * (n + 1));
    int i;
    int j;

    for (i = 0; i < n + 1; i++)
        res[i] = 0;
    j = 0;
    i = 1;
    while (i < num) {
        if (strcmp_newisland(res, split[i]) == 0) {
            res[j] = mx_strdup(split[i]);
            j++;
        }
        i++;
    }
    return res;
}
