#include "pathfinder.h"

static long long get_len(char *s) {
    int i = 0;
    long long n = 1;
    long long r = 0;

    while (s[i] != '\n')
        i++;
    i--;
    while (i >= 0) {
        r += (s[i] - '0') * n;
        n = n * 10;
        i--;
    }
    return r;
}

void mx_valid_maxint(char *s) {
    int i = 0;
    long long sum = 0;

    while (s[i] != '\0') {
        while (s[i++] != ',' && s[i] != '\0');
        if (s[i] >= '0' && s[i] <= '9') {
            sum += get_len(&s[i]);
            if (sum > 2147483647)
                exit(1);
        }
        else
            break;
    }
}
