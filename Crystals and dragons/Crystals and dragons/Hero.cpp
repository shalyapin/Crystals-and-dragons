#include "Hero.h"
using namespace model;

Hero::Hero(std::string name) {
	x = 0;
	y = 0;
	this->name = name;
	health = 100.0f;
	money = 0;
}

Hero::Hero(){
	x = 0;
	y = 0;
	name = "Player";
	health = 100.0f;
	money = 0;
}

Hero::~Hero() {
	std::list<Object *>::iterator i = equipment.begin();
	while (i != equipment.end()) {
		delete (*i);
		i = equipment.erase(i);
	}
}

float Hero::getHealth() {
	return health;
}

int Hero::getX() {
	return x;
}

int Hero::getY() {
	return y;
}

int Hero::getMoney() {
	return money;
}

std::list<Object *> &Hero::getEquipment() {
	return equipment;
}

void Hero::addItemInEquipment(Object *item) {
	equipment.push_back(item);
}

void Hero::setHealth(float health) {
	this->health = health;
}

void Hero::setX(int x) {
	this->x = x;
}

void Hero::setY(int y) {
	this->y = y;
}

void Hero::addMoney(int add) {
	money += add;
}

std::string Hero::getName() {
	return name;
}