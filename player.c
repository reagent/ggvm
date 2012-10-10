#include <stdlib.h>
#include <string.h>
#include "player.h"

Player *player_create(char *name)
{
  Player *player = malloc(sizeof(Player));

  player->name   = strdup(name);
  player->health = 10;

  return player;
}

int player_destroy(Player *player)
{
  free(player->name);
  free(player);

  return 0;
}