#ifndef HERO_H
#define HERO_H

#include "Unit.h"
#include "Object.h"
#include <list>

namespace model {
	class Hero : public Unit {
		int x;
		int y;
		int money;
		float health;
		std::string name;
		std::list<Object *> equipment;
	public:
		Hero();
		Hero(std::string name);
		~Hero();

		int getX();
		int getY();
		int getMoney();
		float getHealth();
		std::string getName();
		std::list<Object *> &getEquipment();

		void addMoney(int add);
		void setX(int x);
		void setY(int y);
		void setHealth(float add);
		void addItemInEquipment(Object *item);
	};
}

#endif