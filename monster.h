#ifndef _monster_h
#define _monster_h

struct Monster {
  char *name;
  int health;
};

typedef struct Monster Monster;

Monster *monster_create(char *name);
int monster_destroy(Monster *monster);

#endif