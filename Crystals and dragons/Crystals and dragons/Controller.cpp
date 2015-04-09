#include "Controller.h"
#include <ctime>
#include <iostream>
using namespace controller;
using namespace model;

Controller::Controller(Model *model) {
	this->model = model;
}

void Controller::readCommand() {
	std::string command;

	if (model->hasMonsterInLocation()) {
		
		double start = clock();
		std::getline(std::cin, command);
		double end = (clock() - start) / CLOCKS_PER_SEC;
		handleInput(command, end);
	
	} else {
		std::getline(std::cin, command);
		handleInput(command);
	}

}

void Controller::handleInput(std::string command, double spentTime) {
	if (spentTime <= 5) {
		double probability = (rand() % 101) * 1.0 / 100.0;
		if (probability < 1.0 / 3) {
			model->returnHeroInLastRoom();
			return;
		}

		if (probability >= (1.0 / 3) && probability < (2.0 / 3)) {
			model->biteOfMonster();
			handleInput(command);
			return;
		}

		if (probability >= (2.0 / 3) && probability <= 1.0) {
			handleInput(command);
			return;
		}
	} else {
		model->returnHeroInLastRoom();
	}
}

void Controller::handleInput(std::string command) {

	int lengthSubStr = 0;

	for (int i = 0; i < command.length(); i++) {
		command[i] = towlower(command[i]);
	}

	if (command == "n" || command == "s" || command == "e" || command == "w") {
		model->moveHero(command);
		return;
	}

	bool flag = true;

	for (int i = 0; i < command.length(); i++) {
		lengthSubStr = i;
		if (command.at(i) == ' ') {
			flag = false;
			break;
		}
	}

	std::string action;
	std::string object;
	if (flag)
		action = command;
	else {
		action = command.substr(0, lengthSubStr);
		object = command.substr(lengthSubStr + 1, command.length());
	}

	if (action == "get") {
		model->commandGetItem(object);
		return;
	}

	if (action == "drop") {
		model->commandDropItem(object);
		return;
	}

	if (action == "eat") {
		model->commandEat(object);
		return;
	}

	if (action == "fight") {
		model->fight();
		return;
	}

	if (action == "open") {
		model->openChest();
		return;
	}

	model->unknownCommand();
}

bool Controller::endGame() {
	return model->theEnd();
}