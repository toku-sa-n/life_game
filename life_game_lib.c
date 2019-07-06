#include <curses.h>
#include <stdio.h>
#include <stdlib.h>

void** two_dimension_calloc(size_t __height, size_t __width, size_t __size)
{
    void** two_dimension_array = calloc(__height, sizeof(__size));
    if (two_dimension_array == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < __height; i++) {
        two_dimension_array[i] = calloc(__width, sizeof(__size));

        if (two_dimension_array[i] == NULL) {
            // Free memories which have already allocated.
            // Not include two_dimension_array[i]
            // because two_dimension_array[j] is NULL.
            for (size_t j = 0; j < i; j++) {
                free(two_dimension_array[j]);
            }
            free(two_dimension_array);
            return NULL;
        }
    }

    return two_dimension_array;
}

// Free the memories of array which were allocated by two_dimension_calloc function.
void free_two_dimension_array(size_t __height, void** __array)
{
    for (size_t i = 0; i < __height; i++) {
        free(__array[i]);
    }
    free(__array);
}

void init_life_game(int __height, int __width, int** __array)
{
    for (int i = 0; i < __height; i++) {
        for (int j = 0; j < __width; j++) {
            __array[i][j] = rand() % 2;
        }
    }
}

void print_table(int __height, int __width, int** array)
{
    for (int i = 0; i < __height; i++) {
        for (int j = 0; j < __width; j++) {
            printf("%3d ", array[i][j]);
        }
        putchar('\n');
    }
}

void print_table_with_ncurses(int __height, int __width, int** __array)
{
    for (int y = 0; y < __height; y++) {
        for (int x = 0; x < __width; x++) {
            move(y, x);
            if (__array[y][x] == 1) {
                addch('@');
            } else {
                addch(' ');
            }
        }
    }
    refresh();
}

// Investigate each elements of __current_generation and assign -1, 0 or 1 to __next_generation_table
// -1 represents that the life in that square will die in next generation, 0 represents it remains in next generation,
// and 1 represents that a new life will appear in next generation.
void proceed_generation(int __height, int __width, int** __current_generation_table, int** __next_generation_table)
{
    for (int y = 0; y < __height; y++) {
        for (int x = 0; x < __width; x++) {
            int alive_num = 0;

            // TODO: Too much evaluation. Decrease it.
            if (y > 0 && x > 0 && __current_generation_table[y - 1][x - 1] == 1) {
                alive_num++;
            }
            if (y > 0 && __current_generation_table[y - 1][x] == 1) {
                alive_num++;
            }
            if (y > 0 && x < __width - 1 && __current_generation_table[y - 1][x + 1] == 1) {
                alive_num++;
            }
            if (x > 0 && __current_generation_table[y][x - 1] == 1) {
                alive_num++;
            }
            if (x < __width - 1 && __current_generation_table[y][x + 1] == 1) {
                alive_num++;
            }
            if (y < __height - 1 && x > 0 && __current_generation_table[y + 1][x - 1] == 1) {
                alive_num++;
            }
            if (y < __height - 1 && __current_generation_table[y + 1][x] == 1) {
                alive_num++;
            }
            if (y < __height - 1 && x < __width - 1 && __current_generation_table[y + 1][x + 1] == 1) {
                alive_num++;
            }

            if ((alive_num <= 1 || alive_num >= 4) && __current_generation_table[y][x] == 1) {
                __next_generation_table[y][x] = -1;
            } else if (alive_num == 3 && __current_generation_table[y][x] == 0) {
                __next_generation_table[y][x] = 1;
            } else {
                __next_generation_table[y][x] = 0;
            }
        }
    }
}

// array_1 += array_2
void add_two_array(int __height, int __width, int** __array_1, int** __array_2)
{
    for (int i = 0; i < __height; i++) {
        for (int j = 0; j < __width; j++) {
            __array_1[i][j] += __array_2[i][j];
        }
    }
}
