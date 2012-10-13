#ifndef _player_h
#define _player_h

#include "structs.h"

Player *player_create();
void player_attack(Player *player, Monster *monster);
int player_destroy(Player *player);

#endif