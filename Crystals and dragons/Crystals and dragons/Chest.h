#ifndef CHEST_H
#define CHEST_H

#include "Object.h"

namespace model {
	class Chest : public Object {
	private:
		int id;
	public:

		Chest() {
			id = chest;
		}

		std:: string getName() {
			return "chest";
		}

		int getID() {
			return id;
		}
	};
}

#endif