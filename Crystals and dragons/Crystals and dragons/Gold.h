#ifndef GOLD_H
#define GOLD_H

#include "Object.h"

namespace model {
	class Gold : public Object {
	private:
		int id;
	public:

		Gold() {
			id = gold;
		}

		std::string getName() {
			return "gold";
		}

		int getID() {
			return id;
		}

		~Gold() {

		}
	};
}

#endif