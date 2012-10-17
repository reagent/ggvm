#ifndef _structs_h
#define _structs_h

typedef enum {
  NORTH, SOUTH, EAST, WEST
} Direction;

struct Weapon {
  char *name;
  int damage;
};

typedef struct Weapon Weapon;

struct Player {
  int health;
  int weapon_count;
  Weapon **arsenal;
  Weapon *weapon;
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
  Weapon *weapon;

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