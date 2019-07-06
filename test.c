#include "life_game_lib.h"
#include <stdio.h>

void two_dimension_calloc_int_test(void)
{
    int height = 50000;
    int width = 50000;
    int** two_dimension_array = two_dimension_calloc_int((size_t)height, (size_t)width);
    free_two_dimension_array((size_t)height, two_dimension_array);
}

void init_life_game_test(void)
{
    int height = 10;
    int width = 10;
    int** life_game_table = two_dimension_calloc_int((size_t)height, (size_t)width);
    init_life_game(height, width, life_game_table);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", life_game_table[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
    free_two_dimension_array((size_t)height, life_game_table);
}

void print_table_test(void)
{
    int height = 10;
    int width = 10;
    int** array = two_dimension_calloc_int((size_t)height, (size_t)width);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            array[i][j] = i + j;
        }
    }
    print_table(height, width, array);
    putchar('\n');

    free_two_dimension_array((size_t)height, array);
}

void proceed_generation_test(void)
{
    int height = 5;
    int width = 5;
    int** life_game_table = two_dimension_calloc_int((size_t)height, (size_t)width);
    int** next_generation_table = two_dimension_calloc_int((size_t)height, (size_t)width);

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

    free_two_dimension_array((size_t)height, life_game_table);
    free_two_dimension_array((size_t)height, next_generation_table);
}

void add_two_array_test(void)
{
    int height = 5;
    int width = 5;

    int** array_1 = two_dimension_calloc_int((size_t)height, (size_t)width);
    int** array_2 = two_dimension_calloc_int((size_t)height, (size_t)width);

    init_life_game(height, width, array_1);
    init_life_game(height, width, array_2);

    puts("array_1");
    print_table(height, width, array_1);
    puts("array_2");
    print_table(height, width, array_2);

    add_two_array(height, width, array_1, array_2);

    puts("array_1 + array_2");
    print_table(height, width, array_1);

    free_two_dimension_array((size_t)height, array_1);
    free_two_dimension_array((size_t)height, array_2);
}

int main(void)
{
    two_dimension_calloc_int_test();
    init_life_game_test();
    print_table_test();
    proceed_generation_test();
    add_two_array_test();

    return 0;
}
