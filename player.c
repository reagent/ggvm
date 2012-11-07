#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "player.h"
#include "weapon.h"

void player_add_weapon(Player *player, Weapon *weapon)
{
  int index = player->weapon_count;
  
  player->arsenal = realloc(player->arsenal, (player->weapon_count +1) * sizeof(Weapon *));
  player->weapon_count++;

  *(player->arsenal + index) = weapon;
}

Player *player_create(char *name)
{
  Player *player = malloc(sizeof(Player));

  player->arsenal        = NULL;
  player->weapon_count   = 0;
  player->health         = 10;
  player->default_weapon = weapon_create("Fist", 1);

  player_add_weapon(player, player->default_weapon);

  return player;
}

void player_show_arsenal(Player *player)
{
  int i = 0;

  printf("You have the following weapons in your arsenal:\n");

  for(i = 0; i < player->weapon_count; i++) {
    weapon_describe(player->arsenal[i]);
  }
}

void player_equip(Player *player, Weapon *weapon)
{
  player_add_weapon(player, weapon);

  printf("You have picked up the %s, it can do a maximum of %d damage.\n",
         weapon->name,
         weapon->damage);
}

Weapon *player_current_weapon(Player *player)
{
  return player->arsenal[player->weapon_count -1];
}

int player_attack(Player *player, Monster *monster)
{
  int killed             = 0;
  Weapon *current_weapon = player_current_weapon(player);
  int maximum_damage     = current_weapon->damage;

  if (current_weapon) { maximum_damage = current_weapon->damage; }

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
  weapon_destroy(player->default_weapon);
  
  free(player->arsenal);
  free(player);

  return 0;
}