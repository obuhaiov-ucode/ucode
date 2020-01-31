#include "pathfinder.h"

static void printint_err(int n, char c) {
    if (n == -2147483648) {
        write(2, "-2", 2);
        n = 147483648;
    }
    if (n < 0) {
        write(2, "-", 1);
        n = -n;
    }
    if (n > 9)
        printint_err(n / 10, '0');
    c = n % 10 + '0';
    write(2, &c, 1);
}

void mx_print_err(int err, char *v1) {
    if (err == 2) {
        write(2, "error: file ", 12);
        write(2, v1, mx_strlen(v1));
        write(2, " doesn't exist\n", 15);
    }
    if (err == 3) {
        write(2, "error: file ", 12);
        write(2, v1, mx_strlen(v1));
        write(2, " is empty\n", 10);
    }
    if (err == 6)
        write(2, "error: invalid number of islands\n", 33);
    if (err < 0) {
        err = -err;
        write(2, "error: line ", 12);
        printint_err(err, '0');
        write(2, " isn't valid\n", 13);
    }
}
