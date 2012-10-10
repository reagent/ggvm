CFLAGS=-Wall -g

all: ggvm

ggvm: monster.o room.o player.o map.o

clean:
	rm -rf *.o *.dSYM ggm