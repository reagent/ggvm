#ifndef _map_h
#define _map_h

#include "room.h"

struct Map {
  Room *location;
};

typedef struct Map Map;

Map *map_create(Room *start);
void map_move(Map *map, Direction direction);
void map_print_directions(Map *map);
int map_destroy(Map *map);

#endif