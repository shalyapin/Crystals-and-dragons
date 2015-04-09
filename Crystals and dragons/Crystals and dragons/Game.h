#ifndef GAME_H
#define GAME_H

#include "Controller.h"
#include "View.h"
#include "Model.h"

class Game {
	model::Model *model;
	controller::Controller *controller;
	view::View *view;
public:
	Game(std::string name, int numberOfRooms);
	~Game();
	void run();
};

#endif