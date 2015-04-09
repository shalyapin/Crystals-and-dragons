#ifndef UNIT_H
#define UNIT_H

#include <string>

namespace model {
	class Unit {
	public:
		virtual int getX() = 0;
		virtual int getY() = 0;
		virtual void setX(int x) = 0;
		virtual void setY(int y) = 0;
		virtual std::string getName() = 0;
		virtual ~Unit() {}
		static Unit* createUnit(int idUnit, std::string name);
	};
}

#endif