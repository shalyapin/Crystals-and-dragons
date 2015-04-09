#ifndef LOCATION_H
#define LOCATION_H

#include "idLocation.h"
#include <string>

namespace model {
	class Location {
	public:
		virtual std::string getName() = 0;
		virtual int getID() = 0;
		virtual ~Location();
		static Location* createObject(int idLocation);
	};
}

#endif