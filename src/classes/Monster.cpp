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

Monster::~Monster() {}

string Monster::getName() const { return name; }

float Monster::getCr() const { return cr; }

string Monster::getType() const { return type; }

string Monster::getSize() const { return size; }

int Monster::getAc() const { return ac; }

int Monster::getHp() const { return hp; }

string Monster::getAlign() const { return align; }
