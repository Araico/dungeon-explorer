#pragma once

#include "../utils/LinkedList/LinkedList.h"
#include "./Monster.h"

class MonsterManager {
  private:
   LinkedList<Monster> monsterList;

  public:
   void AddMonster(Monster monster);
   MonsterManager(/* args */);
   Monster getMonsterAtIndex(int index);
   int getMonsterCount();
};
