#include "life_game_lib.h"
#include <stdio.h>

void print_four_four_array(int array[][4])
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", array[i][j]);
        }
        putchar('\n');
    }
}
int is_two_arrays_equal_size_four(int array_1[][4], int array_2[][4])
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (array_1[i][j] != array_2[i][j]) {
                fprintf(stderr, "array 1 and array 2 are not the same!\n");
                fprintf(stderr, "array 1:");
                print_four_four_array(array_1);
                fprintf(stderr, "array 2:");
                print_four_four_array(array_2);
                return 0;
            }
        }
    }
    return 1;
}

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

int two_array_equal_test(void)
{
    int array_1[][4] = {
        { 3, 1, 4, 1 },
        { 2, 2, 3, 5 },
        { 2, 1, -3, 0 },
        { 5, 6, 9, -9 },
    };

    int array_2[][4] = {
        { 3, 1, 4, 1 },
        { 2, 2, 3, 5 },
        { 2, 1, -3, 0 },
        { 5, 6, 9, -9 },
    };

    return !is_two_arrays_equal_size_four(array_1, array_2);
}

int main(void)
{
    two_dimension_calloc_int_test();
    init_life_game_test();
    print_table_test();
    proceed_generation_test();
    if (two_array_equal_test()) {
        return 1;
    };

    return 0;
}
