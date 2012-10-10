#include <stdlib.h>
#include <string.h>
#include "room.h"

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

int room_destroy(Room *room)
{
  free(room->name);
  free(room);

  return 0;
}
