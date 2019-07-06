#include "life_game_lib.h"
#include <stdio.h>

void two_dimension_calloc_test(void)
{
    int** two_dimension_array = (int**)two_dimension_calloc(50000, 50000, sizeof(int));
    free_two_dimension_array((size_t)50000, (void**)two_dimension_array);
}

void init_life_game_test(void)
{
    int** life_game_table = (int**)two_dimension_calloc(10, 10, sizeof(int));
    init_life_game(10, 10, life_game_table);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", life_game_table[i][j]);
        }
        putchar('\n');
    }
    free_two_dimension_array((size_t)10, (void**)life_game_table);
}

int main(void)
{
    two_dimension_calloc_test();
    init_life_game_test();

    return 0;
}
