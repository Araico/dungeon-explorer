#include "Dungeon.h"

Dungeon::Dungeon() {}

Dungeon::Dungeon(Monster* monster) : monster(monster) {}

Monster* Dungeon::getMonster() { return monster; }

bool Dungeon::operator>(const Dungeon& other) const { return false; }