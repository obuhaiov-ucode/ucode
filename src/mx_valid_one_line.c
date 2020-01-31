#include "pathfinder.h"

static int int_v(char c) {
    if (c >= '0' && c <= '9')
        return 1;
    else
        return 0;
}

static int is_char_v(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    else
        return 0;
}

static int maybe_dubl(char *s, int sec) {
    int i = 0;

    for (; s[i] == s[sec] && s[sec] != '\0'; i++) {
        if (s[i + 1] == '-' && s[sec + 1] == ',') {
            if (s[sec + 2] == '0')
                return 1;
        }
        sec++;
    }
    return 0;
}

int mx_valid_one_line(char *s, int i) {
    while (is_char_v(s[i++]) == 1);
    if (maybe_dubl(s, i))
        return 1;
    i--;
    if (s[i] == '-' && i != 0) {
        i++;
        while (is_char_v(s[i++]) == 1);
        i--;
        if (s[i] == ',') {
            i++;
            if ((s[i] == '0' && s[i + 1] != '\n') || !(int_v(s[i])))
                return 1;
            while (int_v(s[i++]) == 1);
            if (s[--i] != '\n')
                return 1;
            return 0;
        }
        return 1;
    }
    return 1;
}
