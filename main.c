#include "life_game_lib.h"
#include <curses.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int is_verbose(const int argc, char* const* argv)
{
    const char* optstring = "v";
    const struct option longopts[] = {
        { "verbose", no_argument, 0, 1 },
        { 0, 0, 0, 0 },
    };

    int c;
    int longindex = 0;
    while ((c = getopt_long(argc, argv, optstring, longopts, &longindex)) != -1) {
        if (c == 1) {
            return 1;
        }
        if (c == 'v') {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char** argv)
{
    initscr();
    cbreak();
    noecho();
    refresh();

    int verbose = is_verbose(argc, argv);

    int width = COLS;
    int height = LINES;

    if (verbose) {
        height--;
    }

    // 1: Alive 0: Dead
    int** life_game_table = two_dimension_calloc_int((size_t)height, (size_t)width);

    // 1: Birth 0: No change -1: Die
    int** life_game_next_generation_table = two_dimension_calloc_int((size_t)height, (size_t)width);

    srand((unsigned int)time(NULL));
    init_life_game(height, width, life_game_table);

    timeout(0);

    long generation = 0;

    while (getch() != 'q') {
        print_table_with_ncurses(height, width, life_game_table);
        if (verbose) {
            mvprintw(LINES - 1, 0, "Generation %ld", generation++);
        }
        proceed_generation(height, width, life_game_table, life_game_next_generation_table);
        add_two_array(height, width, life_game_table, life_game_next_generation_table);
        refresh();
        usleep(100000);
    }

    free_two_dimension_array((size_t)height, life_game_table);
    free_two_dimension_array((size_t)height, life_game_next_generation_table);

    endwin();
    return 0;
}
