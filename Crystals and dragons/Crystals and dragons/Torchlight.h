#ifndef TORCHLIGHT_H
#define TORCHLIGHT_H

#include "Object.h"

namespace model {
	class Torchlight : public Object {
	private:
		int id;
	public:
		Torchlight() {
			id = torchlight;
		}

		std::string getName() {
			return "torchlight";
		}

		int getID() {
			return id;
		}

		~Torchlight() {

		}
	};
}

#endif