#include "Model.h"
using namespace model;

Model::Model(std::string name, int numberOfRooms) {
	hero = new Hero(name);
	world = new World(numberOfRooms, hero);
	foundGrail = false;
}

void Model::registerObserver(Observer *observer) {
	observers.push_back(observer);
}

void Model::removeObserver(Observer *observer) {
	observers.remove(observer);
}

void Model::notifyObservers(ActionType type) {
	for (std::list<Observer*>::iterator i = observers.begin(); i != observers.end(); ) {
		(*i)->update(type);
		i++;
	}
}

void Model::moveHero(std::string direction) {
	int x = hero->getX();
	int y = hero->getY();
	previousX = x;
	previousY = y;
	switch (direction.at(0)) {
	case 'n':
		--x;
		updatePositionHero(x, y, north);
		break;
	case 's':
		++x;
		updatePositionHero(x, y, south);
		break;
	case 'e':
		++y;
		updatePositionHero(x, y, east);
		break;
	case 'w':
		--y;
		updatePositionHero(x, y, west);
		break;
	}
}

void Model::updatePositionHero(int x, int y, int direction) {

	if (!(((Room*)world->getLocation())->existDoor(direction))) {
		notifyObservers(HeroHitWall);
	}
	else {
		hero->setX(x);
		hero->setY(y);
		float health = hero->getHealth();
		health -= 0.5f;
		hero->setHealth(health);
		notifyObservers(HeroMove);
	}


	if (checkRoomIsDark() == HeroInDarkRoom) {
		notifyObservers(HeroInDarkRoom);
	}

	if (hasMonsterInLocation()) {
		notifyObservers(HeroSeeMonsterInRoom);
	}
}

void Model::biteOfMonster() {
	float health = hero->getHealth();
	hero->setHealth(health - health * 0.1f);
	notifyObservers(MonsterBitHero);
}

void Model::returnHeroInLastRoom() {
	hero->setX(previousX);
	hero->setY(previousY);

	biteOfMonster();
	notifyObservers(MonsterThrewHero);

	if (checkRoomIsDark() == HeroInDarkRoom) {
		notifyObservers(HeroInDarkRoom);
	}

	if (hasMonsterInLocation()) {
		notifyObservers(HeroSeeMonsterInRoom);
	}
}

ActionType Model::checkRoomIsDark() {
	std::list<Object *> equipment = hero->getEquipment();
	bool heroHasTorchlight = false;

	if (isThereATypeElement("torchlight", equipment) != NULL)
		heroHasTorchlight = true;

	if (((Room*)(world->getLocation()))->isDark() && !heroHasTorchlight)
		return HeroInDarkRoom;
	else
		return HeroMove;
}

void Model::commandGetItem(std::string item) {
	
	if (checkRoomIsDark() == HeroInDarkRoom) {
		notifyObservers(HeroInDarkRoom);
		return;
	}

	if (hasMonsterInLocation()) {
		notifyObservers(HeroSeeMonsterInRoom);
	}

	std::list<Object *> &listItemInRoom = ((Room*)(world->getLocation()))->getListItemsInRoom();
	Object* object = isThereATypeElement(item, listItemInRoom);

	if (object != NULL) {
		if (object->getID() != chest) {
			hero->addItemInEquipment(object);
			if (item == "gold")
				hero->addMoney(320);

			if (item == "torchlight")
			if (((Room*)(world->getLocation()))->isIlluminateByTorchlight())
				((Room*)(world->getLocation()))->setDark(true);

			listItemInRoom.remove(object);
		} else {
			notifyObservers(HeroGetChest);
		}
	} else 
		notifyObservers(LocationHasNotItem);
}

void Model::commandDropItem(std::string item) {

	if (checkRoomIsDark() == HeroInDarkRoom) {
		notifyObservers(HeroInDarkRoom);
		return;
	}

	if (hasMonsterInLocation()) {
		notifyObservers(HeroSeeMonsterInRoom);
	}

	std::list<Object *> &equipment = hero->getEquipment();

	Object* object = isThereATypeElement(item, equipment);

	if (object != NULL) {
		((Room*)(world->getLocation()))->addObjects(object);

		if (item == "gold")
			hero->addMoney(-320);

		if (item == "torchlight")
		if (((Room*)(world->getLocation()))->isIlluminateByTorchlight())
			((Room*)(world->getLocation()))->setDark(false);

		equipment.remove(object);
	}
	else
		notifyObservers(HeroHasNotItem);
}

void Model::commandEat(std::string item) {
	
	if (checkRoomIsDark() == HeroInDarkRoom) {
		notifyObservers(HeroInDarkRoom);
		return;
	}

	if (hasMonsterInLocation()) {
		notifyObservers(HeroSeeMonsterInRoom);
	}

	std::list<Object *> &equipment = hero->getEquipment();
	Object* object = isThereATypeElement(item, equipment);

	if (object != NULL) {
		if (object->getID() == eat) {
			equipment.remove(object);
			float health = hero->getHealth();

			hero->setHealth(health + health * 0.1f);
			notifyObservers(HeroEat);
		} else 
			notifyObservers(HeroCanNotEat);
	}
	else
		notifyObservers(HeroHasNotItem);
}

bool Model::hasMonsterInLocation() {
	std::list<Unit *> listMonsters = ((Room*)(world->getLocation()))->getListMonsters();
	if (!listMonsters.empty())
		return true;
	else
		return false;
}

void Model::fight() {

	if (checkRoomIsDark() == HeroInDarkRoom) {
		notifyObservers(HeroInDarkRoom);
		if (hasMonsterInLocation()) {
			notifyObservers(HeroSeeMonsterInRoom);
		}
		return;
	}

	std::list<Unit *> &listMonsters = ((Room*)(world->getLocation()))->getListMonsters();
	if (!listMonsters.empty()) {
		std::list<Object *> equipment = hero->getEquipment();
		Object* object = isThereATypeElement("sword", equipment);
		
		if (object != NULL) {
			listMonsters.pop_back();
			notifyObservers(HeroKilledMonster);
		}
		else {
			notifyObservers(HeroHasNotItem);
			notifyObservers(HeroSeeMonsterInRoom);
		}
	}
	else {
		notifyObservers(HeroNotSeeMonster);
	}
}

void Model::openChest() {

	if (hasMonsterInLocation()) {
		notifyObservers(HeroSeeMonsterInRoom);
	}

	if (checkRoomIsDark() == HeroInDarkRoom) {
		notifyObservers(HeroInDarkRoom);
		return;
	}

	std::list<Object *> equipment = hero->getEquipment();
	std::list<Object *> listItemsInRoom = ((Room*)(world->getLocation()))->getListItemsInRoom();
	Object* key = isThereATypeElement("key", equipment);
	Object* chest = isThereATypeElement("chest", listItemsInRoom);
	
	if (key != NULL && chest != NULL)  {
		notifyObservers(HeroOpenChest);
		foundGrail = true;
	}
	else {
		notifyObservers(HeroHasNotItem);
	}
}

Object* Model::isThereATypeElement(std::string item, std::list<Object *> listObjects) {

	for (std::list<Object *>::iterator i = listObjects.begin(); i != listObjects.end();) {
		if ((*i)->getName() == item) {
			return (*i);
		}
		++i;
	}
	
	return NULL;
}

std::string Model::getNameHero() {
	return hero->getName();
}

float Model::getHealtHero() {
	return hero->getHealth();
}

std::string Model::getEquipmentHero() {
	std::list<Object *> equipment = hero->getEquipment();
	std::string items = "";

	for (std::list<Object *>::iterator i = equipment.begin(); i != equipment.end();) {
		items += (*i)->getName();
		++i;
		if (i != equipment.end())
			items += ", ";
	}

	return items;
}

void Model::unknownCommand() {
	if (checkRoomIsDark() == HeroInDarkRoom) {
		notifyObservers(HeroInDarkRoom);
	}

	if (hasMonsterInLocation()) {
		notifyObservers(HeroSeeMonsterInRoom);
	}

	notifyObservers(UnknownCommand);
}

int Model::getPositionHero_X() {
	return hero->getX();
}

int Model::getPositionHero_Y() {
	return hero->getY();
}

int Model::getNumberOfDoors() {
	return ((Room*)(world->getLocation()))->getNumberOfDoorsInRoom();
}

std::string Model::getDirections() {
	return ((Room*)(world->getLocation()))->getDirection();
}

std::string Model::getMonsters() {
	std::list<Unit *> listMonsters = ((Room*)(world->getLocation()))->getListMonsters();
	
	std::string monsters = "";

	for (std::list<Unit *>::iterator i = listMonsters.begin(); i != listMonsters.end();) {
		monsters += (*i)->getName();
		++i;
		if (i != listMonsters.end())
			monsters += ", ";
	}

	return monsters;
}

std::string Model::getItems() {
	std::list<Object *> objectsInRoom = ((Room*)(world->getLocation()))->getListItemsInRoom();
	std::string items = "";

	for (std::list<Object *>::iterator i = objectsInRoom.begin(); i != objectsInRoom.end();) {
		items += (*i)->getName();
		++i;
		if (i != objectsInRoom.end())
			items += ", ";
	}

	return items;

}

int Model::getNumberMoneyOfHero() {
	return hero->getMoney();
}

bool Model::theEnd() {
	if (hero->getHealth() <= 0)
		return true;
	else
		return foundGrail;
}

Model::~Model() {
	delete world;
	delete hero;

	std::list<Observer *>::iterator i = observers.begin();
	while (i != observers.end()) {
		i = observers.erase(i);
	}
}