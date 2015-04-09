#ifndef BORDER_H
#define BORDER_H

#include "Location.h"

namespace model {
	class Border : public Location {
	private:
		int id;
	public:

		Border() {
			id = border;
		}

		int getID() {
			return id;
		}

		std::string getName() {
			return "border";
		}

		~Border() {

		}
	};
}

#endif