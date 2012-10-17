#ifndef _weapon_h
#define _weapon_h

#include "structs.h"

Weapon *weapon_create(char *name, int damage);
void weapon_describe(Weapon *weapon);
int weapon_destroy(Weapon *weapon);

#endif