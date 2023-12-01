#pragma once

#include <string>
using namespace std;

class Monster {

  private:
   string name;
   float cr;
   string type;
   string size;
   int ac;
   int hp;
   string align;

  public:
   Monster(string name, float cr, string type, string size, int ac, int hp,
           string align);
   Monster();
   Monster(const Monster& monsterRef);

   ~Monster();

   string getName() const;
   float getCr() const;
   string getType() const;
   string getSize() const;
   int getAc() const;
   int getHp() const;
   string getAlign() const;

   void takeDamage(int dmg);

   bool operator>(const Monster& other) const;
};
