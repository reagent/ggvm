#ifndef _player_h
#define _player_h

struct Player {
  char *name;
  int health;
};

typedef struct Player Player;

Player *player_create(char *name);
int player_destroy(Player *player);

#endif