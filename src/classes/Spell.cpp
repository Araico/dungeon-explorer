#include "Spell.h"

Spell::Spell() {}

Spell::Spell(string name, string type, string description, int value)
    : name(name), type(type), description(description), value(value) {}

string Spell::getName() { return name; }

string Spell::getType() { return type; }

string Spell::getDescription() { return description; }

int Spell::getValue() { return value; }

bool Spell::operator>(const Spell& other) const { return false; }
