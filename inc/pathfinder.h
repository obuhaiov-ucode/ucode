#ifndef PATHFINDER
#define PATHFINDER

#include "libmx/inc/libmx.h"

void mx_del_matrix(int **arr);
void mx_valid_maxint(char *s);
void mx_print_err(int err, char *v1);
void mx_hardkostuling(char **names, int *path);
void mx_refresh_dijkstra(int ***dijkstra, int n);
void mx_refresh_matrix(int ***dijkstra, int **matrix, int n);
void mx_print_this_sht(char **names, int ***dijkstra, int ***pathes);

int mx_get_int(char *s);
int mx_valid(char *file);
int mx_get_real_int(char *s);
int mx_dia_len(int **matrix);
int mx_get_first(int **dijk, int n);
int mx_valid_one_line(char *s, int i);
int mx_get_next(int **dijk, int prev, int n);
int mx_get_direct_next(int *dijkstra, int n);
int mx_any_dubl(int **dijk, int **arr, int r, int n);
int mx_nex_dubl(int **dijk, int prev, int closed, int n);

int *mx_first_fill(int *dijkstra, int *matrix, int isl);

int **mx_matrix_empty(int *isl_index);
int **mx_islands_matrix(char **names, char **split, int y, int x);

int ***mx_create_dijkstra(int n);
int ***mx_dijkstra(int **matrix);
int ***mx_fill_pathes(int ***dijkstra);

char *mx_file_to_str_v(const char *file);

char **mx_isl_to_str(const char *file);
char **mx_island_as_unistring(char **split);

#endif
