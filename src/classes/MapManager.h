#include "../DataStructures/LinkedList/LinkedList.h"
#include "Dungeon.h"

class MapManager {
  private:
   static LinkedList<Dungeon> dungeonList;

  public:
   static Dungeon getDungeonAtIndex(int index);

   static void generateMap();
};
