#include "pathfinder.h"

static int malloc_file(const char *file) {
    int fp = open(file, O_RDONLY);
    char c;
    int i = 0;

    while (read(fp,&c,1))
        i++;
    close(fp);
    return i;
}

char *mx_file_to_str_v(const char *file) {
    int fp = open(file, O_RDONLY);
    char c;
    int i = 0;

    if ((fp = open(file, O_RDONLY)) < 0) {
        write(2, "error: file ", 12);
        write(2, file, mx_strlen(file));
        write(2, " does not exist\n", 16);
        exit(1);
    }
    else if ((read(fp, (void *)0, 0) < 0) || fp == -1) {
        write(2, "usage: ./pathfinder [filename]\n", 31);
        exit(1);
    }
    char *s = mx_strnew(malloc_file(file));
    while (read(fp, &c, 1))
        s[i++] = c;
    s[i] = '\0';
    close(fp);
    return s;
}
