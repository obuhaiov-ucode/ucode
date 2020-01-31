NAME = pathfinder

LIB = ./libmx/libmx.a

INC = ./inc/pathfinder.h

HEAD = pathfinder.h

SRCS = ./src/mx_del_matrix.c \
	./src/mx_valid_maxint.c \
	./src/mx_print_err.c \
	./src/mx_hardkostuling.c \
	./src/mx_refresh_dijkstra.c \
	./src/mx_refresh_matrix.c \
	./src/mx_print_this_sht.c \
	./src/mx_get_int.c \
	./src/mx_valid.c \
	./src/mx_get_real_int.c \
	./src/mx_dia_len.c \
	./src/mx_get_first.c \
	./src/mx_valid_one_line.c \
	./src/mx_get_next.c \
	./src/mx_get_direct_next.c \
	./src/mx_any_dubl.c \
	./src/mx_nex_dubl.c \
	./src/mx_first_fill.c \
	./src/mx_matrix_empty.c \
	./src/mx_islands_matrix.c \
	./src/mx_create_dijkstra.c \
	./src/mx_dijkstra.c \
	./src/mx_fill_pathes.c \
	./src/mx_file_to_str_v.c \
	./src/mx_isl_to_str.c \
	./src/mx_island_as_unistring.c \
	./src/main.c \

SRCOUT = mx_del_matrix.c \
	mx_valid_maxint.c \
	mx_print_err.c \
	mx_hardkostuling.c \
	mx_refresh_dijkstra.c \
	mx_refresh_matrix.c \
	mx_print_this_sht.c \
	mx_get_int.c \
	mx_valid.c \
	mx_get_real_int.c \
	mx_dia_len.c \
	mx_get_first.c \
	mx_valid_one_line.c \
	mx_get_next.c \
	mx_get_direct_next.c \
	mx_any_dubl.c \
	mx_nex_dubl.c \
	mx_first_fill.c \
	mx_matrix_empty.c \
	mx_islands_matrix.c \
	mx_create_dijkstra.c \
	mx_dijkstra.c \
	mx_fill_pathes.c \
	mx_file_to_str_v.c \
	mx_isl_to_str.c \
	mx_island_as_unistring.c \
	main.c \

OBJS = ./obj/mx_del_matrix.o \
	./obj/mx_valid_maxint.o \
	./obj/mx_print_err.o \
	./obj/mx_hardkostuling.o \
	./obj/mx_refresh_dijkstra.o \
	./obj/mx_refresh_matrix.o \
	./obj/mx_print_this_sht.o \
	./obj/mx_get_int.o \
	./obj/mx_valid.o \
	./obj/mx_get_real_int.o \
	./obj/mx_dia_len.o \
	./obj/mx_get_first.o \
	./obj/mx_valid_one_line.o \
	./obj/mx_get_next.o \
	./obj/mx_get_direct_next.o \
	./obj/mx_any_dubl.o \
	./obj/mx_nex_dubl.o \
	./obj/mx_first_fill.o \
	./obj/mx_matrix_empty.o \
	./obj/mx_islands_matrix.o \
	./obj/mx_create_dijkstra.o \
	./obj/mx_dijkstra.o \
	./obj/mx_fill_pathes.o \
	./obj/mx_file_to_str_v.o \
	./obj/mx_isl_to_str.o \
	./obj/mx_island_as_unistring.o \
	./obj/main.o \

OBJOUT = mx_del_matrix.o \
	mx_valid_maxint.o \
	mx_print_err.o \
	mx_hardkostuling.o \
	mx_refresh_dijkstra.o \
	mx_refresh_matrix.o \
	mx_print_this_sht.o \
	mx_get_int.o \
	mx_valid.o \
	mx_get_real_int.o \
	mx_dia_len.o \
	mx_get_first.o \
	mx_valid_one_line.o \
	mx_get_next.o \
	mx_get_direct_next.o \
	mx_any_dubl.o \
	mx_nex_dubl.o \
	mx_first_fill.o \
	mx_matrix_empty.o \
	mx_islands_matrix.o \
	mx_create_dijkstra.o \
	mx_dijkstra.o \
	mx_fill_pathes.o \
	mx_file_to_str_v.o \
	mx_isl_to_str.o \
	mx_island_as_unistring.o \
	main.o \

CFLAG = -std=c11 -Wall -Wextra -Wpedantic -Werror

all: install clean

install:
	@make install -C libmx
	@cp $(SRCS) .
	@cp $(INC) .
	@clang $(CFLAGS) -c $(SRCOUT) -I $(HEAD)
	@clang $(CFLAGS) $(LIB) $(OBJOUT) -o $(NAME)
	@mkdir -p obj
	@mv $(OBJOUT) ./obj

clean:
	@rm -rf $(OBJOUT) $(SRCOUT) $(HEAD) obj
	@make uninstall -C libmx

uninstall: clean
	@make clean -C libmx
	@rm -rf $(NAME)

reinstall: uninstall all