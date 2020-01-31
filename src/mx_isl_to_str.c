#include "pathfinder.h"

static int malloc_fil(const char *file) {
    int fp = open(file, O_RDONLY);
    char c;
    int i = 0;

    while (read(fp,&c,1))
        i++;
    close(fp);
    return i;
}

char **mx_isl_to_str(const char *file) {
    int fp = open(file, O_RDONLY);
    char **split = NULL;
    char c;
    int i = 0;
    char *s = mx_strnew(malloc_fil(file));

    while (read(fp,&c,1)) {
        if (c == '\n' || c == '-' || c == ',') {
            s[i++] = '$';
        }
        else
            s[i++] = c;
    }
    s[i] = '\0';
    split = mx_strsplit(s, '$');
    mx_strdel(&s);
    s = NULL;
    return split;
}
