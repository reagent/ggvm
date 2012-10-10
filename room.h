#ifndef _room_h
#define _room_h

#include "monster.h"

typedef enum {
  NORTH, SOUTH, EAST, WEST
} Direction;

struct Room {
  char *name;

  Monster *monster;

  struct Room *north;
  struct Room *south;
  struct Room *east;
  struct Room *west;
};

typedef struct Room Room;

Room *room_create(char *name);
void room_attach(Room *source, Room *destination, Direction direction);
int room_destroy(Room *room);

#endif