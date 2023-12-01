#pragma once

#include <iostream>
#include "../DataStructures/LinkedList/LinkedList.h"
#include "Monster.h"
#include "Spell.h"

class Player {
  private:
   string name;
   string race;
   int hp = 10;
   int lp = 100;
   LinkedList<Monster> defeatedMonsters;

  public:
   Player(string name);
   Player();

   void setHp(int newHp);
   void setLp(int newLp);

   int getLp();
   int getHp();

   void addDefeatedMonster(Monster monster);
   LinkedList<Monster> getDefeatedMonsters();
};
