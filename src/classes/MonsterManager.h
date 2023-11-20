#pragma once

#include "../DataStructures/LinkedList/LinkedList.h"
#include "./Monster.h"

class MonsterManager {
  private:
   static LinkedList<Monster> monsterList;

  public:
   static void AddMonster(Monster monster);
   static Monster getMonsterAtIndex(int index);
   static int getMonsterCount();
};
