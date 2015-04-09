#include "Game.h"
#include <iostream>

int main() {
	std::string name;
	int numberOfRoom;
	
	std::cout << "Enter the name of the hero - > ";
	std::getline(std::cin, name);
	std::cout << "Enter the number of room - > ";
	std::cin >> numberOfRoom;
	std::cin.get();

	Game *game = new Game(name, numberOfRoom);
	game->run();

	delete game;
	return 0;
}