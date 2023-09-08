#pragma once

#include <string>
#include "../enums/SpellEnums.h"
using namespace std;
using namespace SpellEnums;

class Spell {

  private:
   int level;
   string name;
   School school;

   RangeType rangeType;
   int range;

   CastType castType;
   int castTime;

   bool verbalComponent;
   bool somaticComponent;
   bool materialComponent;

   string iconPath;

  public:
   Spell(int level, string name, School school, RangeType rangeType, int range,
         CastType castType, int castTime, bool verbalComponent,
         bool somaticComponent, bool materialComponent, string iconPath);
   ~Spell();

   int getLevel() const;
   string getName() const;
   School getSchool() const;

   RangeType getRangeType() const;
   int getRange() const;

   CastType getCastType() const;
   int getCastTime() const;

   bool getVerbalComponent() const;
   bool getSomaticComponent() const;
   bool getMaterialComponent() const;
};
