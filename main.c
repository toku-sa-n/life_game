#include "life_game_lib.h"
#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(void)
{
    initscr();
    cbreak();
    noecho();
    refresh();

    int height = LINES;
    int width = COLS;

    // 1: Alive 0: Dead
    int** life_game_table = (int**)two_dimension_calloc((size_t)height, (size_t)width, sizeof(int));
    ;

    // 1: Birth 0: No change -1: Die
    int** life_game_next_generation_table = (int**)two_dimension_calloc((size_t)height, (size_t)width, sizeof(int));

    srand((unsigned int)time(NULL));
    init_life_game(height, width, life_game_table);

    for (int i = 0; i < 100; i++) {
        print_table_with_ncurses(height, width, life_game_table);
        proceed_generation(height, width, life_game_table, life_game_next_generation_table);
        add_two_array(height, width, life_game_table, life_game_next_generation_table);
        refresh();
        usleep(100000);
    }

    free_two_dimension_array((size_t)height, (void**)life_game_table);
    free_two_dimension_array((size_t)height, (void**)life_game_next_generation_table);

    endwin();
    return 0;
}
