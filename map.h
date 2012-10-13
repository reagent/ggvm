#ifndef _map_h
#define _map_h

#include "structs.h"

Map *map_create(Room *start, Player *player);
int map_has_location_at(Map *map, Direction direction);
void map_move(Map *map, Direction direction);
void map_attack(Map *map);
void map_print_directions(Map *map);
int map_destroy(Map *map);

#endif