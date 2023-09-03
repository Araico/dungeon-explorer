#include "Spell.h"

Spell::Spell(int level, string name, School school, RangeType rangeType,
             int range, CastType castType, int castTime, bool verbalComponent,
             bool somaticComponent, bool materialComponent, string iconPath)
    : level(level),
      name(name),
      school(school),
      rangeType(rangeType),
      range(range),
      castType(castType),
      castTime(castTime),
      verbalComponent(verbalComponent),
      somaticComponent(somaticComponent),
      materialComponent(materialComponent),
      iconPath(iconPath) {}

int Spell::getLevel() const { return level; }

string Spell::getName() const { return name; }

School Spell::getSchool() const { return school; }

RangeType Spell::getRangeType() const { return rangeType; }

int Spell::getRange() const { return range; }

CastType Spell::getCastType() const { return castType; }

int Spell::getCastTime() const { return castTime; }

bool Spell::getVerbalComponent() const { return verbalComponent; }

bool Spell::getSomaticComponent() const { return somaticComponent; }

bool Spell::getMaterialComponent() const { return materialComponent; }
