#pragma once

#include <string>
using namespace std;

class Spell {

  private:
   string name;
   string type;
   string description;
   int value;

  public:
   Spell();
   Spell(string name, string type, string description, int value);

   string getName();
   string getType();
   string getDescription();
   int getValue();

   bool operator>(const Spell& other) const;
};
