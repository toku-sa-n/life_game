#include <curses.h>
#include <stdio.h>
#include <stdlib.h>

// Returns positive reminder.
int positive_modulo(int number, int denom)
{
    return (number % denom + denom) % denom;
}

// Creates two-dimension array and returns the pointer to that.
// After calling this function, User must call free_two_dimension_array function.
int** two_dimension_calloc_int(size_t __height, size_t __width)
{
    int** two_dimension_array = calloc(__height, sizeof(int*));
    if (two_dimension_array == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < __height; i++) {
        two_dimension_array[i] = calloc(__width, sizeof(int));

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

// Free the memories of array which were allocated by two_dimension_calloc_int function.
void free_two_dimension_array(size_t __height, int** __array)
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

void print_table(int __height, int __width, int** __array)
{
    for (int i = 0; i < __height; i++) {
        for (int j = 0; j < __width; j++) {
            printf("%3d ", __array[i][j]);
        }
        putchar('\n');
    }
}

// Print two-dimension array with ncurses function.
// After calling this function, user must call refresh() to print characters actually.
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
}

// Investigate each elements of __current_generation and assign -1, 0 or 1 to __next_generation_table
// -1 represents that the life in that square will die in next generation, 0 represents it remains in next generation,
// and 1 represents that a new life will appear in next generation.
void proceed_generation(int __height, int __width, int** __current_generation_table, int** __next_generation_table)
{
    for (int y = 0; y < __height; y++) {
        for (int x = 0; x < __width; x++) {
            int alive_num = 0;

            // positive_modulo function is needed in order to fit the value within range.
            // ex. when y == 0, y - 1 == -1 but positive_modulo(y - 1, y) == y - 1.
            int y_coord[] = {
                positive_modulo(y - 1, __height),
                y,
                positive_modulo(y + 1, __height),
            };
            int x_coord[] = {
                positive_modulo(x - 1, __width),
                x,
                positive_modulo(x + 1, __width),
            };

            for (int y_idx = 0; y_idx < 3; y_idx++) {
                for (int x_idx = 0; x_idx < 3; x_idx++) {
                    if (y_idx == x_idx && x_idx == 1) {
                        // exclude coord (y, x).
                        continue;
                    }

                    if (__current_generation_table[y_coord[y_idx]][x_coord[x_idx]] == 1) {
                        alive_num++;
                    }
                }
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
