#include "Game.h"
#include <string>
#include "ConsoleColor.h"
#include <ctime>
Game::Game(std::string name, int numberOfRooms) {
	model = new model::Model(name, numberOfRooms);
	view = new view::View(model);
	controller = new controller::Controller(model);
}

void Game::run() {
	view->display();

	while (!controller->endGame()) {
		std::cout << blue << "Enter the command --- >    ";
		controller->readCommand();
		view->display();
	}

	std::cout << yellow << "-------------------- Game over! --------------------" << std::endl;
}

Game::~Game() {
	delete model;
	delete view;
	delete controller;
}