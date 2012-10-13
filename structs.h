#ifndef _structs_h
#define _structs_h

typedef enum {
  NORTH, SOUTH, EAST, WEST
} Direction;

struct Player {
  int health;
};

typedef struct Player Player;

struct Monster {
  char *name;
  int health;
};

typedef struct Monster Monster;

struct Room {
  char *name;

  Monster *monster;

  struct Room *north;
  struct Room *south;
  struct Room *east;
  struct Room *west;
};

typedef struct Room Room;

struct Map {
  Room *location;
  Player *player;
};

typedef struct Map Map;

#endif