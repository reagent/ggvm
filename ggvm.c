#include <stdlib.h>
#include <stdio.h>
#include "monster.h"
#include "room.h"
#include "player.h"
#include "map.h"

int main(int argc, char *argv[])
{
  Room *hall    = room_create("Hall");
  Room *throne  = room_create("Throne");
  Room *arena   = room_create("Arena");
  Room *kitchen = room_create("Kitchen");

  Monster *monster = monster_create("Minotaur");
  arena->monster = monster;

  room_attach(hall, throne, NORTH);
  room_attach(throne, kitchen, EAST);
  room_attach(throne, arena, WEST);

  Map *map = map_create(hall);
  map_print_directions(map);

  map_move(map, NORTH);
  puts("");
  map_print_directions(map);

  map_move(map, EAST);
  puts("");
  map_print_directions(map);

  room_destroy(hall);
  room_destroy(throne);
  room_destroy(arena);
  room_destroy(kitchen);
  monster_destroy(monster);
  map_destroy(map);

  return 0;
}