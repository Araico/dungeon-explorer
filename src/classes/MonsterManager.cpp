#include "MonsterManager.h"
#include <iostream>

LinkedList<Monster> MonsterManager::monsterList;

void MonsterManager::AddMonster(Monster monster) {
   monsterList.insert(monster);
   // std::cout << monster.getName() << std::endl;
}

Monster MonsterManager::getMonsterAtIndex(int index) {
   return monsterList[index];
}

int MonsterManager::getMonsterCount() { return monsterList.getLength(); }
