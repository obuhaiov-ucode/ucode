#include "pathfinder.h"

static int num_lines(char *s) {
    int num = 0;
    int i = 0;

    while (s[i] != '\0') {
        if (s[i] == '\n')
            num++;
        else if (s[i + 1] == '\0' && s[i] != '\n')
            num++;
        i++;
    }
    return num;
}

static int valid_lines(char *s) {
    int real_num = num_lines(s);
    int row_num = -2;
    int err = 0;
    int i = 0;

    while (s[i] != '\0') {
        while (s[i++] != '\n' && s[i] != '\0');
        err = mx_valid_one_line(&s[i], 0);
        if (err > 0)
            return row_num;
        row_num--;
        if (real_num + 1 == -row_num)
            return 0;
    }
    return 0;
}

static int valid_firstrow(char *s) {
    int n = 0;
    int i = 0;

    mx_get_int(s);
    if (s[0] == '0' && (s[1] == '\n' || s[1] == '\0'))
        exit(0);
    while (s[i] != '\0' && s[i] != '\n') {
        if (s[i] >= '0' && s[i] <= '9')
            n++;
        i++;
    }
    if (n == i && n != 0 && n <= 10)
        return 0;
    return 1;
}

static int valid_number(char *s) {
    int real_num = mx_get_real_int(s);
    int lines_num = num_lines(s);
    int file_num = mx_get_int(s);
    int i = 0;

    mx_valid_maxint(s);
    if (real_num == file_num && real_num <= lines_num) {
    	if (s[0] == '1' && s[1] == '\n') {
    		for (i = 2; s[i] != '\n' && s[i] != '\0'; i++);
    		if (s[i + 1] == '\0')
        	    exit(0);
    	}
        return 0;
    }
    return 6;
}

int mx_valid(char *file) {
    char *s = mx_file_to_str_v(file);
    int fp = 0;
    int err = 0;
    char c;

    if ((fp = open(file, O_RDONLY)) < 0)
        err = 2;
    else if (read(fp, &c, 1) == 0)
        err = 3;
    else if (valid_firstrow(s))
        err = -1;
    else
        err = valid_lines(s);
    if (err == 0)
        err = valid_number(s);
    close(fp);
    free(s);
    return err;
}
