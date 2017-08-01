CC=g++
CFLAGS= -Wall -Wextra -Werror

all: main.o
	$(CC) $(CFLAGS) $< -o tic_tac_toe

main.o: main.cpp draw.cpp draw.h
	$(CC) -o main.cpp draw.cpp draw.h

clean:
	rm -rf *.o tic_tac_toe
