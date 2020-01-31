#include "pathfinder.h"

static int is_chr(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    else
        return 0;
}

static int count_islands_for_malloc(char *s) {
    int i = 0;
    int n = 0;

    while (s[i++] != '\n');
    while (s[i] != '\0') {
        if (is_chr(s[i]) == 1) {
            n++;
            if (is_chr(s[i + 1]) != 1)
                n++;
        }
        i++;
    }
    return n;
}

static char *get_islands_as_string(char *s) {
    int real_num = count_islands_for_malloc(s);
    char *islands = mx_strnew(real_num);
    int i = 0;
    int n = 0;

    while (s[i++] != '\n');
    while (n < real_num && s[i]) {
        if (is_chr(s[i]) == 1) {
            islands[n] = s[i];
            n++;
            if (is_chr(s[i+1]) != 1) {
                islands[n] = ' ';
                n++;
            }
        }
        i++;
    }
    return islands;
}

static char **bub_sort(char **arr, int size) {
    int i = 0;
    int j = 0;
    char *t = 0;

    while (size > j) {
        i = 0;
        while (size > i + 1) {
            if (mx_strcmp(arr[i], arr[i+1]) > 0) {
                t = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = t;
            }
            i++;
        }
        j++;
    }
    return arr;
}

int mx_get_real_int(char *s) {
    char *res = get_islands_as_string(s);
    int n = mx_count_words(res, 32);
    char **islands = bub_sort(mx_strsplit(res, ' '), n);
    int x = 1;

    for (int i = 0; n > i + 1; i++)
        if ((mx_strcmp(islands[i], islands[i + 1]) != 0)
            && islands[i + 1] && islands[0])
            x++;
    for (int i = 0; islands[i]; i++)
        free(islands[i]);
    free(islands);
    free(res);
    return x;
}
