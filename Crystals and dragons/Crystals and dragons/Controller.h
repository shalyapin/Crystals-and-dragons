#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Model.h"
#include <string>

namespace controller {
	class Controller {
		model::Model *model;
		void handleInput(std::string command);
		void handleInput(std::string command, double spentTime);
	public:
		Controller(model::Model *model);
		void readCommand();
		bool endGame();
	};
}

#endif 