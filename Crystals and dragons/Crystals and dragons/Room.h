#ifndef ROOM_H
#define ROOM_H

#include "Location.h"
#include "Meat.h"
#include "Water.h"
#include "Gold.h"
#include "Torchlight.h"
#include "Sword.h"
#include "Chest.h"
#include "Key.h"
#include "Monster.h"
#include "Direction.h"
#include <list>

namespace model {
	class Room : public Location{
	private:
		int id;
		bool North;
		bool East;
		bool West;
		bool South;
		bool Dark;
		bool illuminateByTorchlight;
		int doors;
		std::list<Object *> objectsInRoom;
		std::list<Unit *> monsters;
	public:
		Room();
		~Room();
		std::string getName();
		std::string getDirection();
		std::list<Object *> &getListItemsInRoom();
		std::list<Unit *> &getListMonsters();
		int getNumberOfDoorsInRoom();
		int getID();
		bool isDark();
		bool isIlluminateByTorchlight();
		bool existDoor(int direction);

		void setDirection(Direction open);
		void setDark(bool dark);
		void addObjects(Object* object);
		void addMonster(Unit* monster);
	};
}

#endif