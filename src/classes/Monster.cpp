#include "Monster.h"

Monster::Monster(string name, float cr, string type, string size, int ac,
                 int hp, string align)
    : name(name),
      cr(cr),
      type(type),
      size(size),
      ac(ac),
      hp(hp),
      align(align) {}

Monster::Monster() {}

Monster::Monster(const Monster& monsterRef)
    : name(monsterRef.getName()),
      cr(monsterRef.getCr()),
      type(monsterRef.getType()),
      size(monsterRef.getSize()),
      ac(monsterRef.getAc()),
      hp(monsterRef.getHp()),
      align(monsterRef.getAlign()) {}

Monster::~Monster() {}

string Monster::getName() const { return name; }

float Monster::getCr() const { return cr; }

string Monster::getType() const { return type; }

string Monster::getSize() const { return size; }

int Monster::getAc() const { return ac; }

int Monster::getHp() const { return hp; }

string Monster::getAlign() const { return align; }

void Monster::takeDamage(int dmg) { hp -= dmg; }

bool Monster::operator>(const Monster& other) const {
   return this->name > other.getName();
}
