#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "monster.h"
#include "room.h"
#include "player.h"
#include "map.h"
#include "weapon.h"

int process_input(Map *game)
{
  printf("\n> ");

  char ch = getchar();
  getchar(); // eat ENTER

  switch(ch) {
    case -1:
    case 'q':
      printf("Giving up? Too bad.\n");
      return 0;
      break;
    case 'n':
      map_move(game, NORTH);
      break;
    case 's':
      map_move(game, SOUTH);
      break;
    case 'e':
      map_move(game, EAST);
      break;
    case 'w':
      map_move(game, WEST);
      break;
    case 'a':
      map_attack(game);
      break;
    case 'p':
      map_equip(game);
      break;
    case 'l':
      map_print_directions(game);
      break;
    default:
      printf("What?: %d\n", ch);
  }

  return 1;
}


int main(int argc, char *argv[])
{
  srand(time(NULL));

  Room *hall         = room_create("Hall");
  Room *throne       = room_create("Throne");
  Room *arena        = room_create("Arena");
  Room *kitchen      = room_create("Kitchen");
  Room *gate         = room_create("Gate");
  Room *cannon       = room_create("Cannon Room");
  Room *tower        = room_create("Tower");
  Room *garden       = room_create("Garden");
  Room *maze         = room_create("Maze");
  Room *boat         = room_create("Boat Room");
  Room *super_vision = room_create("Super Vision Room");
  Room *hut          = room_create("Hut Room");

  Weapon *knife = weapon_create("Knife", 5);
  Weapon *axe   = weapon_create("Axe", 7);
  Weapon *sword = weapon_create("Sword", 10);
  Weapon *bow   = weapon_create("Bow", 15);

  Player *player = player_create();

  Monster *minotaur  = monster_create("Minotaur");
  Monster *mcm       = monster_create("Million-clawed Monster");
  Monster *crazy_cat = monster_create("Crazy Cat");
  Monster *jumpy     = monster_create("Jumpy Bumpy");
  Monster *slime     = monster_create("Slime Monster");

  arena->monster        = minotaur;
  gate->monster         = mcm;
  cannon->monster       = crazy_cat;
  boat->monster         = jumpy;
  super_vision->monster = slime;

  kitchen->weapon      = knife;
  garden->weapon       = axe;
  cannon->weapon       = sword;
  super_vision->weapon = bow;

  room_attach(hall, throne, NORTH);
  room_attach(hall, gate, SOUTH);
  room_attach(throne, kitchen, EAST);
  room_attach(throne, arena, WEST);
  room_attach(throne, tower, NORTH);
  room_attach(kitchen, cannon, EAST);
  room_attach(tower, garden, NORTH);
  room_attach(garden, maze, WEST);
  room_attach(garden, boat, EAST);
  room_attach(gate, super_vision, WEST);
  room_attach(garden, hut, NORTH);

  Map *map = map_create(hall, player);

  while(process_input(map)) {
    // NOOP
  }

  room_destroy(hall);
  room_destroy(throne);
  room_destroy(arena);
  room_destroy(kitchen);
  room_destroy(gate);
  room_destroy(cannon);
  room_destroy(tower);
  room_destroy(garden);
  room_destroy(maze);
  room_destroy(boat);
  room_destroy(super_vision);
  room_destroy(hut);

  monster_destroy(minotaur);
  monster_destroy(mcm);
  monster_destroy(crazy_cat);
  monster_destroy(jumpy);
  monster_destroy(slime);

  player_destroy(player);

  weapon_destroy(knife);
  weapon_destroy(axe);
  weapon_destroy(sword);
  weapon_destroy(bow);

  map_destroy(map);

  return 0;
}