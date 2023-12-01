#include "Player.h"

Player::Player(string name, string race) : name(name), race(race) {}

Player::Player() {}

void Player::setHp(int newHp) { hp = newHp; }

void Player::setLp(int newLp) { lp = newLp > 999 ? 999 : newLp; }

int Player::getLp() { return lp; }

int Player::getHp() { return hp; }

string Player::getName() { return name; }

string Player::getRace() { return race; }

void Player::addDefeatedMonster(Monster monster) {
   defeatedMonsters.insert(monster);
}

LinkedList<Monster> Player::getDefeatedMonsters() { return defeatedMonsters; }
