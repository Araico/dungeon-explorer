#include "Player.h"

Player::Player(string name) : name(name) {}

void Player::setHp(int newHp) { hp = newHp; }

void Player::setLp(int newLp) { lp = newLp > 999 ? 999 : newLp; }

int Player::getLp() { return lp; }

int Player::getHp() { return hp; }
