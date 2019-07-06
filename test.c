#include "life_game_lib.h"
#include <stdio.h>

void two_dimension_calloc_test(void)
{
    int height = 50000;
    int width = 50000;
    int** two_dimension_array = (int**)two_dimension_calloc((size_t)height, (size_t)width, sizeof(int));
    free_two_dimension_array((size_t)height, (void**)two_dimension_array);
}

void init_life_game_test(void)
{
    int height = 10;
    int width = 10;
    int** life_game_table = (int**)two_dimension_calloc((size_t)height, (size_t)width, sizeof(int));
    init_life_game(height, width, life_game_table);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", life_game_table[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
    free_two_dimension_array((size_t)height, (void**)life_game_table);
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

void proceed_generation_test(void)
{
    int height = 5;
    int width = 5;
    int** life_game_table = (int**)two_dimension_calloc((size_t)height, (size_t)width, sizeof(int));
    int** next_generation_table = (int**)two_dimension_calloc((size_t)height, (size_t)width, sizeof(int));

    init_life_game(height, width, life_game_table);
    proceed_generation(height, width, life_game_table, next_generation_table);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", life_game_table[i][j]);
        }
        putchar('\n');
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%3d ", next_generation_table[i][j]);
        }
        putchar('\n');
    }

    free_two_dimension_array((size_t)height, (void**)life_game_table);
    free_two_dimension_array((size_t)height, (void**)next_generation_table);
}

void add_two_array_test(void)
{
    int height = 5;
    int width = 5;

    int** array_1 = (int**)two_dimension_calloc((size_t)height, (size_t)width, sizeof(int));
    int** array_2 = (int**)two_dimension_calloc((size_t)height, (size_t)width, sizeof(int));

    init_life_game(height, width, array_1);
    init_life_game(height, width, array_2);

    puts("array_1");
    print_table(height, width, array_1);
    puts("array_2");
    print_table(height, width, array_2);

    add_two_array(height, width, array_1, array_2);

    puts("array_1 + array_2");
    print_table(height, width, array_1);

    free_two_dimension_array((size_t)height, (void**)array_1);
    free_two_dimension_array((size_t)height, (void**)array_2);
}

int main(void)
{
    two_dimension_calloc_test();
    init_life_game_test();
    print_table_test();
    proceed_generation_test();
    add_two_array_test();

    return 0;
}
