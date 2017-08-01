CC=clang++
CFLAGS= -Wall -Wextra -Werror

all: main.o draw.o game.o
	$(CC) $(CFLAGS) main.o draw.o game.o -o tic_tac_toe

main.o: main.cpp draw.cpp draw.h game.cpp game.h
	$(CC) -c main.cpp draw.cpp draw.h game.cpp game.h

game.o: game.cpp game.h draw.cpp draw.h
	$(CC) -c game.cpp game.h draw.cpp draw.h

draw.o: draw.cpp draw.h
	$(CC) -c draw.cpp draw.h

clean:
	rm -rf *.o tic_tac_toe
