#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "room.h"

#include "monster.h"
#include "player.h"

Room *room_create(char *name)
{
  Room *room = malloc(sizeof(Room));

  room->north = NULL;
  room->south = NULL;
  room->east  = NULL;
  room->west  = NULL;

  room->name    = strdup(name);
  room->monster = NULL;

  return room;
}

void room_attack(Room *room, Player *player)
{
  if (room->monster != NULL) {
    player_attack(player, room->monster);
    monster_attack(room->monster, player);
  } else {
    printf("You flail in the air at nothing.\n");
  }
}

void room_attach(Room *source, Room *destination, Direction direction)
{
  switch(direction) {
    case NORTH:
      source->north = destination;
      destination->south = source;
      break;
    case SOUTH:
      source->south = destination;
      destination->north = source;
      break;
    case EAST:
      source->east = destination;
      destination->west = source;
      break;
    case WEST:
      source->west = destination;
      destination->east = source;
      break;
  }
}

void room_print_description(Room *room)
{
  printf("You have entered the %s\n", room->name);
  if(room->monster != NULL) {
    printf("You encounter the %s!\n", room->monster->name);
  }
}

int room_destroy(Room *room)
{
  free(room->name);
  free(room);

  return 0;
}
