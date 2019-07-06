CC=gcc
CFLAGS=-Wall -O2 -pipe -march=native -lncurses
DEPS=life_game_lib.h
BUILD=main.o life_game_lib.o
TEST=test.o life_game_lib.o
PROGRAM_NAME=main

%.o:%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

build:$(BUILD)
	$(CC) -o $(PROGRAM_NAME) $^ $(CFLAGS)

run:
	./main

run_verbose:
	./main --verbose

test:$(TEST)
	$(CC) -o $@ $^ $(CFLAGS)
	./test
	rm test
	make clean

.PHONY: clean

clean:
	rm -f $(BUILD) $(TEST) $(PROGRAM_NAME)
