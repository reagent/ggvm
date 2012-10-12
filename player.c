#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "player.h"

Player *player_create(char *name)
{
  Player *player = malloc(sizeof(Player));

  player->health = 10;

  return player;
}

void player_attack(Player *player, Monster *monster)
{
  int hit    = rand() % 2;
  int damage = (rand() % 5) + 1;

  if (hit == 1) {
    if (monster->health <= 0) {
      printf("You strike at the lifeless corpse of the %s.\n", monster->name);
    } else {

      printf("You land a powerful blow. It does %d damage.\n", damage);
      monster->health -= damage;

      if (monster->health <= 0) {
        printf("You have defeated the %s!\n", monster->name);
      }
    }
  } else {
    printf("You swing and miss.\n");
  }
}

int player_destroy(Player *player)
{
  free(player);

  return 0;
}