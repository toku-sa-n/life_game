#include "life_game_lib.h"
#include <stdio.h>

int is_two_arrays_equal(int height, int width, int** array_1, int** array_2)
{
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (array_1[y][x] != array_2[y][x]) {
                fprintf(stderr, "Test failed! array_1 is not the same with array_2!\n");
                fprintf(stderr, "array_1:\n");
                print_table(height, width, array_1);
                putchar('\n');
                fprintf(stderr, "array_2:\n");
                print_table(height, width, array_2);
                putchar('\n');
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
    int** array_1 = two_dimension_calloc_int(2, 2);
    int** array_2 = two_dimension_calloc_int(2, 2);

    array_1[0][0] = 0;
    array_1[0][1] = 1;
    array_1[1][0] = 2;
    array_1[1][1] = 3;

    array_2[0][0] = 0;
    array_2[0][1] = 1;
    array_2[1][0] = 2;
    array_2[1][1] = 3;

    if (!is_two_arrays_equal(2, 2, array_1, array_2)) {
        free_two_dimension_array(2, array_1);
        free_two_dimension_array(2, array_2);
        return 1;
    }
    return 0;
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
