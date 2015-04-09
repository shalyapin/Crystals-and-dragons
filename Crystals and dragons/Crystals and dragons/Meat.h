#ifndef MEAT_H
#define MEAT_H

#include "Object.h"

namespace model {
	class Meat : public Object {
	private:
		int id;
	public:

		Meat() {
			id = eat;
		}

		std::string getName() {
			return "meat";
		}

		int getID() {
			return id;
		}

		~Meat() {

		}
	};
}

#endif