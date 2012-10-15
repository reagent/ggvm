#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "player.h"

Player *player_create(char *name)
{
  Player *player = malloc(sizeof(Player));

  player->health = 10;
  player->weapon = NULL;

  return player;
}

void player_equip(Player *player, Weapon *weapon)
{
  player->weapon = weapon;
  printf("You have picked up the %s, it can do a maximum of %d damage.\n",
         player->weapon->name,
         player->weapon->damage);
}

int player_attack(Player *player, Monster *monster)
{
  int killed         = 0;
  int maximum_damage = 1;

  if (player->weapon) { maximum_damage = player->weapon->damage; }

  int hit    = rand() % 2;
  int damage = (rand() % maximum_damage) + 1;

  if (hit == 1) {
    if (monster->health <= 0) {
      printf("You strike at the lifeless corpse of the %s.\n", monster->name);
      killed = 1;
    } else {
      printf("You land a powerful blow. It does %d damage.\n", damage);
      monster->health -= damage;

      if (monster->health <= 0) {
        printf("You have defeated the %s!\n", monster->name);
        killed = 1;
      }
    }
  } else {
    printf("You swing and miss.\n");
  }

  return killed;
}

int player_destroy(Player *player)
{
  free(player);

  return 0;
}