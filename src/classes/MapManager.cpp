#include "MapManager.h"
#include "MonsterManager.h"

LinkedList<Dungeon> MapManager::dungeonList;

Dungeon MapManager::getDungeonAtIndex(int index) { return dungeonList[index]; }

void MapManager::generateMap() {
   LinkedList<Dungeon> newList;
   dungeonList = newList;

   for (int i = 0; i < 20; i++) {
      int randomIndex = rand() % MonsterManager::getMonsterCount();
      dungeonList.insert(MonsterManager::getMonsterAtIndex(randomIndex));
   }
}
