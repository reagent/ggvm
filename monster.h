#ifndef _monster_h
#define _monster_h

#include "structs.h"

Monster *monster_create(char *name);
void monster_attack(Monster *monster, Player *player);
int monster_destroy(Monster *monster);

#endif