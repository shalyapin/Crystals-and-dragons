#include "Room.h"
using namespace model;

Room::Room() {
	id = room;
	North = false;
	West = false;
	East = false;
	South = false;
	Dark = false;
	illuminateByTorchlight = false;
	doors = 0;
}

std::string Room::getDirection() {
	std::string directions = "";
	if (North) {
		directions += "N ";
	}
	if (East) {
		directions += "E ";
	}
	if (South) {
		directions += "S ";
	}
	if (West) {
		directions += "W ";
	}
	return directions;
}

int Room::getID() {
	return id;
}

void Room::addObjects(Object *object) {
	objectsInRoom.push_back(object);
}

std::list<Object*> &Room::getListItemsInRoom() {
	return objectsInRoom;
}

int Room::getNumberOfDoorsInRoom() {
	return doors;
}

std::string Room::getName() {
	return "room";
}

bool Room::isDark() {
	return Dark;
}

void Room::setDark(bool dark) {
	Dark = dark;
	illuminateByTorchlight = true;
}

bool Room::isIlluminateByTorchlight() {
	return illuminateByTorchlight;
}

std::list<Unit *> &Room::getListMonsters() {
	return monsters;
}

void Room::addMonster(Unit *monster) {
	monsters.push_back(monster);
}

Room::~Room() {
	std::list<Object *>::iterator i = objectsInRoom.begin();
	std::list<Unit *>::iterator j = monsters.begin();

	while (i != objectsInRoom.end()) {
		delete (*i);
		i = objectsInRoom.erase(i);
	}

	while (j != monsters.end()) {
		delete (*j);
		j = monsters.erase(j);
	}
}

void Room::setDirection(Direction open) {
	switch (open) {
	case north:
		North = true;
		++doors;
		break;

	case south:
		South = true;
		++doors;
		break;

	case east:
		East = true;
		++doors;
		break;

	case west:
		West = true;
		++doors;
		break;

	default:
		break;
	}
}

bool Room::existDoor(int direction) {
	switch (direction) {
	case north:
		return North;
	case south:
		return South;
	case west:
		return West;
	case east:
		return East;
	default:
		return false;
	}
}