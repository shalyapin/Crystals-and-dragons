#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include "IdObjects.h"

namespace model {
	class Object {
	public:
		virtual std::string getName() = 0;
		virtual int getID() = 0;
		virtual ~Object() {}
		static Object* createObject(int idObject);
	};
}

#endif