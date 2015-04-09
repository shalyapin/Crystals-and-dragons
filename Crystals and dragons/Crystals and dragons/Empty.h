#ifndef EMPTY_H
#define EMPTY_H

#include "Location.h"

namespace model {
	class Empty : public Location {
	private:
		int id;
	public:
		
		Empty() {
			id = empty;
		}

		int getID() {
			return id;
		}

		std::string getName() {
			return "empty";
		}

		~Empty() {

		}
	};
}

#endif