#include <stdlib.h>
#include <string.h>
#include "weapon.h"

Weapon *weapon_create(char *name, int damage)
{
  Weapon *weapon = malloc(sizeof(Weapon));

  weapon->name = strdup(name);
  weapon->damage = damage;

  return weapon;
}

int weapon_destroy(Weapon *weapon)
{
  free(weapon->name);
  free(weapon);

  return 0;
}