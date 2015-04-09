#ifndef MODEL_H
#define MODEL_H

#include "World.h"
#include "Observable.h"
#include <list>

namespace model {
	class Model : public Observable {
	private:
		std::list<Observer *> observers;
		World *world;
		Hero *hero;
		ActionType checkRoomIsDark();
		void updatePositionHero(int x, int y, int direction);
		Object* isThereATypeElement(std::string item, std::list<Object *> listObjets);
		int previousX;
		int previousY;
		bool foundGrail;
	public:
		Model(std::string name, int numberOfRooms);
		~Model();
		void registerObserver(Observer *observer);
		void removeObserver(Observer *observer);
		void notifyObservers(ActionType type);
		
		void moveHero(std::string direction);
		void commandGetItem(std::string item);
		void commandDropItem(std::string item);
		void commandEat(std::string item);
		void fight();
		bool hasMonsterInLocation();
		void returnHeroInLastRoom();
		void biteOfMonster();
		void openChest();
		void unknownCommand();

		bool theEnd();
		std::string getNameHero();
		float getHealtHero();
		std::string getEquipmentHero();
		int getPositionHero_X();
		int getPositionHero_Y();
		int getNumberOfDoors();
		int getNumberMoneyOfHero();
		std::string getItems();
		std::string getDirections();
		std::string getMonsters();
	};
}

#endif