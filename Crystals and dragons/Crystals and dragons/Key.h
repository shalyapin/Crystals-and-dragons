#ifndef KEY_H
#define KEY_H

#include "Object.h"

namespace model {
	class Key : public Object {
	private:
		int id;
	public:

		Key() {
			id = key;
		}

		std::string getName() {
			return "key";
		}

		int getID() {
			return id;
		}

		~Key() {

		}
	};
}

#endif