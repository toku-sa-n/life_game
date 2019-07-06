#ifndef __LIFE_GAME_LIB
#define __LIFE_GAME_LIB

#include <stddef.h>

int** two_dimension_calloc_int(size_t __height, size_t __width);
void free_two_dimension_array(size_t __height, int** __array);
void init_life_game(int __height, int __width, int** __array);
void print_table(int __height, int __width, int** __array);
void print_table_with_ncurses(int __height, int __width, int** __array);
void proceed_generation(int __height, int __width, int** __current_generation_table, int** __next_generation_table);
void add_two_array(int __height, int __width, int** __array_1, int** __array_2);
#endif
