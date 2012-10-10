#include <stdlib.h>
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

int monster_destroy(Monster *monster)
{
  free(monster->name);
  free(monster);

  return 0;
}