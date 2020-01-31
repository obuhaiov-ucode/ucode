#include "pathfinder.h"

int mx_get_int(char *s) {
    int i = 0;
    long long n = 1;
    long long r = 0;
    int res = 0;

    while (s[i] != '\n')
        i++;
    i--;
    while (i >= 0) {
        r = r + (s[i] - '0') * n;
        n = n * 10;
        i--;
    }
    if (r > 2147483647) {
        write(2, "error: line 1 is not valid\n", 27);
        exit(1);
    }
    res = r;
    return res;
}
