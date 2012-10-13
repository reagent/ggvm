#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "monster.h"
#include "room.h"

Monster *monster_create(char *name)
{
  struct Monster *monster = malloc(sizeof(Monster));

  monster->name   = strdup(name);
  monster->health = 5;

  return monster;
}

void monster_attack(Monster *monster, Player *player)
{
  int hit    = rand() % 2;
  int damage = (rand() % 5) + 1;

  if (hit == 1) {
    if (player->health <= 0) {
      printf("Game over.\n");
    } else {

      printf("The monster lands a powerful attack. It does %d damage.\n", damage);
      player->health -= damage;

      if (player->health <= 0) {
        printf("You have been killed by the %s!\n", monster->name);
      }
    }
  } else {
    printf("The monster lunges, but misses you by mere inches.\n");
  }

}

int monster_destroy(Monster *monster)
{
  free(monster->name);
  free(monster);

  return 0;
}