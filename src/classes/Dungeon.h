#pragma once

#include "Monster.h"

class Dungeon {
  private:
   Monster* monster;

  public:
   Dungeon();
   Dungeon(Monster* monster);
   Monster* getMonster();
};
