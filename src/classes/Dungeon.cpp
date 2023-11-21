#include "Dungeon.h"

Dungeon::Dungeon() {}

Dungeon::Dungeon(Monster* monster) : monster(monster) {}

Monster* Dungeon::getMonster() { return monster; }
