#include "MonsterManager.h"
#include <iostream>

void MonsterManager::AddMonster(Monster monster) {
   monsterList.insert(monster);
   // std::cout << monster.getName() << std::endl;
}

MonsterManager::MonsterManager() {}

Monster MonsterManager::getMonsterAtIndex(int index) {
   return monsterList[index];
}

int MonsterManager::getMonsterCount() { return monsterList.getLength(); }
