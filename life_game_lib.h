#ifndef __LIFE_GAME_LIB
#define __LIFE_GAME_LIB

#include <stddef.h>

void** two_dimension_calloc(size_t __height, size_t __width, size_t __size);
void free_two_dimension_array(size_t __height, void** __array);
void init_life_game(int __height, int __width, int** __array);
#endif
