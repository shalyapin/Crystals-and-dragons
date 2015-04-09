#include "Monster.h"
using namespace model;

Monster::Monster(std::string nameMonster) {
	name = nameMonster;
}

std::string Monster::getName() {
	return name;
}

int Monster::getX() {
	return x; 
}

int Monster::getY() {
	return y;
}

void Monster::setX(int x) {
	this->x = x;
}

void Monster::setY(int y) {
	this->y = y;
}