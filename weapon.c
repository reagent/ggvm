#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "weapon.h"

Weapon *weapon_create(char *name, int damage)
{
  Weapon *weapon = malloc(sizeof(Weapon));

  weapon->name = strdup(name);
  weapon->damage = damage;

  return weapon;
}

void weapon_describe(Weapon *weapon)
{
  printf("* %s (damage: %d)\n", weapon->name, weapon->damage);
}

int weapon_destroy(Weapon *weapon)
{
  free(weapon->name);
  free(weapon);

  return 0;
}