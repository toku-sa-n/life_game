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

void print_table_test(void)
{
    int height = 10;
    int width = 10;
    int** array = (int**)two_dimension_calloc((size_t)height, (size_t)width, sizeof(int));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            array[i][j] = i + j;
        }
    }
    print_table(height, width, array);
    putchar('\n');

    free_two_dimension_array((size_t)height, (void**)array);
}
int main(void)
{
    two_dimension_calloc_test();
    init_life_game_test();
    print_table_test();

    return 0;
}
