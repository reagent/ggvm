#include <stdlib.h>
#include <stdio.h>
#include "map.h"
#include "room.h"

Map *map_create(Room *start, Player *player)
{
  Map *map = malloc(sizeof(Map));

  map->location = start;
  map->player   = player;

  room_print_description(start);

  return map;
}

int map_has_location_at(Map *map, Direction direction)
{
  int has_location = 0;

  switch(direction) {
    case NORTH:
      has_location = map->location->north != NULL;
      break;
    case SOUTH:
      has_location = map->location->south != NULL;
      break;
    case EAST:
      has_location = map->location->east != NULL;
      break;
    case WEST:
      has_location = map->location->west != NULL;
      break;
  }

  return has_location;
}

void map_equip(Map *map)
{
  room_equip(map->location, map->player);
}

void map_move(Map *map, Direction direction)
{
  if(map_has_location_at(map, direction)) {
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
    room_print_description(map->location);
  } else {
    puts("You cannot go there.");
    map_print_directions(map);
  }
}

void map_attack(Map *map)
{
  room_attack(map->location, map->player);
}

void map_print_directions(Map *map)
{
  puts("You can go:");

  if(map->location->north) {
    puts("* NORTH");
  }

  if(map->location->south) {
    puts("* SOUTH");
  }

  if(map->location->east) {
    puts("* EAST");
  }

  if(map->location->west) {
    puts("* WEST");
  }
}

int map_destroy(Map *map)
{
  free(map);

  return 0;
}
