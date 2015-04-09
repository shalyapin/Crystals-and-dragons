#ifndef MONSTER_H
#define MONSTER_H

#include "Unit.h"

namespace model {
	class Monster : public Unit {
		std::string name;
		int x;
		int y;
	public:
		Monster(std::string nameMonster);
		~Monster();
		int getX();
		int getY();
		void setX(int x);
		void setY(int y);
		std::string getName();
	};
}
#endif