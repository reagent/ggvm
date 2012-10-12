#ifndef _player_h
#define _player_h

#include "monster.h"

struct Player {
  int health;
};

typedef struct Player Player;

Player *player_create();
void player_attack(Player *player, Monster *monster);
int player_destroy(Player *player);

#endif