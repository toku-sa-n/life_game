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
