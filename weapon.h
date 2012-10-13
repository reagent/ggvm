#ifndef _weapon_h
#define _weapon_h

#include "structs.h"

Weapon *weapon_create(char *name, int damage);
int weapon_destroy(Weapon *weapon);

#endif