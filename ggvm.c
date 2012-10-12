#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "monster.h"
#include "room.h"
#include "player.h"
#include "map.h"

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

  Room *hall    = room_create("Hall");
  Room *throne  = room_create("Throne");
  Room *arena   = room_create("Arena");
  Room *kitchen = room_create("Kitchen");

  Player *player = player_create();

  Monster *monster = monster_create("Minotaur");
  arena->monster = monster;

  room_attach(hall, throne, NORTH);
  room_attach(throne, kitchen, EAST);
  room_attach(throne, arena, WEST);

  Map *map = map_create(hall, player);

  while(process_input(map)) {
    // NOOP
  }

  room_destroy(hall);
  room_destroy(throne);
  room_destroy(arena);
  room_destroy(kitchen);
  monster_destroy(monster);
  player_destroy(player);
  map_destroy(map);

  return 0;
}