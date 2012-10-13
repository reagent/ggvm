#ifndef _room_h
#define _room_h

#include "structs.h"

Room *room_create(char *name);
void room_equip(Room *room, Player *player);
void room_attack(Room *room, Player *player);
void room_attach(Room *source, Room *destination, Direction direction);
void room_print_description(Room *room);
int room_destroy(Room *room);

#endif