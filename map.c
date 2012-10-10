#include <stdlib.h>
#include <stdio.h>
#include "map.h"

Map *map_create(Room *start)
{
  Map *map = malloc(sizeof(Map));

  map->location = start;

  return map;
}

void map_move(Map *map, Direction direction)
{
  switch(direction) {
    case NORTH:
      map->location = map->location->north;
      break;
    case SOUTH:
      map->location = map->location->south;
      break;
    case EAST:
      map->location = map->location->east;
      break;
    case WEST:
      map->location = map->location->west;
      break;
  }
}

void map_print_directions(Map *map)
{
  if(map->location->north) {
    puts("NORTH");
  }

  if(map->location->south) {
    puts("SOUTH");
  }

  if(map->location->east) {
    puts("EAST");
  }

  if(map->location->west) {
    puts("WEST");
  }
}

int map_destroy(Map *map)
{
  free(map);

  return 0;
}
