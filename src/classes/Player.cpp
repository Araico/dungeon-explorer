#include "Player.h"

Player::Player(string name) : name(name) {}

Player::Player() {}

void Player::setHp(int newHp) { hp = newHp; }

void Player::setLp(int newLp) { lp = newLp > 999 ? 999 : newLp; }

int Player::getLp() { return lp; }

int Player::getHp() { return hp; }

void Player::addDefeatedMonster(Monster monster) {
   defeatedMonsters.insert(monster);
}

LinkedList<Monster> Player::getDefeatedMonsters() { return defeatedMonsters; }
