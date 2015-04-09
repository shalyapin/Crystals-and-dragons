#ifndef WATER_H
#define WATER_H

#include "Object.h"

namespace model {
	class Water : public Object {
	private:
		int id;
	public:

		Water() {
			id = eat;
		}

		std::string getName() {
			return "water";
		}

		int getID() {
			return id;
		}

		~Water() {

		}
	};
}

#endif