#ifndef SWORD_H
#define SWORD_H

#include "Object.h"

namespace model {
	class Sword : public Object {
	private:
		int id;
	public:
		
		Sword() {
			id = sword;
		}

		std::string getName() {
			return "sword";
		}

		int getID() {
			return id;
		}

		~Sword() {

		}
	};
}

#endif