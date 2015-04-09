#ifndef VIEW_H
#define VIEW_H

#include "Observer.h"
#include "Model.h"
#include <Windows.h>

namespace view {
	class View : public Observer {
		model::Model *model;
		HANDLE hStdOut;
		int rowDialogue;
		std::string dialogueHero[20];
		bool isDarkRoom;
	public:
		View(model::Model *model);
		void update(model::ActionType type);
		void display();
	};
}

#endif