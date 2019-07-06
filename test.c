#include "life_game_lib.h"
#include <stdio.h>

void two_dimension_calloc_test(void)
{
    int** two_dimension_array = (int**)two_dimension_calloc(50000, 50000, sizeof(int));
    for (int i = 0; i < 50000; i++) {
        for (int j = 0; j < 50000; j++) {
            two_dimension_array[i][j] = i + j;
        }
    }
    free_two_dimension_array((size_t)50000, (void**)two_dimension_array);
}

int main(void)
{
    two_dimension_calloc_test();
    return 0;
}
