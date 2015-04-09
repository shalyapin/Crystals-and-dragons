#include "World.h"
#include "idUnits.h"
#include <time.h>
using namespace model;

World::World(int n, Hero *myHero) {
	numberOfRooms = n;
	hero = myHero;
	numberRoom = 1;

	// Вычисляем какой длины и ширины будет лабиринт 
	lengthMaze_X = trunc(sqrt(numberOfRooms));
	if (numberOfRooms % lengthMaze_X == 0)
		lengthMaze_Y = trunc(numberOfRooms / lengthMaze_X);
	else
		lengthMaze_Y = trunc(numberOfRooms / lengthMaze_X) + 1;
	// Конец вычислений 

	for (int i = 0; i < lengthMaze_X; i++) {
		for (int j = 0; j < lengthMaze_Y; j++) {
			location[i][j] = Location::createObject(empty);
		}
	}

	generateWorld();
}

void World::generateWorld() {
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, -1, 0, 1 };
	
	srand(time(NULL));

	numberRoomWithChest = rand() % (numberOfRooms) + 1;
	numberRoomWithKey = rand() % (numberOfRooms) + 1;
	
	createRoom(0, 0);
	for (int i = 0; i < 4; i++) {
		int tx = dx[i];
		int ty = dy[i];

		if (tx >= 0 && ty >= 0 && tx < lengthMaze_X && ty < lengthMaze_Y)
			location[tx][ty] = Location::createObject(border);
	}

	// Строим лабиринт по алгоритму Прима
	for (int i = 2; i <= numberOfRooms; i++) {
		int count = 0;

		for (int x = 0; x < lengthMaze_X; x++) {
			for (int y = 0; y < lengthMaze_Y; y++) {
				if (location[x][y]->getName() == "border")
					++count;
			}
		}

		count = rand() % count + 1;
		
		bool flag = false;
		int save_x;
		int save_y;

		for (int x = 0; x < lengthMaze_X; x++) {
			for (int y = 0; y < lengthMaze_Y; y++) {
				if (location[x][y]->getName() == "border") {
					--count;
					if (count == 0) {
						save_x = x;
						save_y = y;
						createRoom(x, y);
						flag = true;
						break;
					}
				}
			}
			if (flag)
				break;
		}

		count = 0;

		for (int k = 0; k < 4; k++) {
			int tx = save_x + dx[k];
			int ty = save_y + dy[k];

			if (tx >= 0 && ty >= 0 && tx < (lengthMaze_X) && ty < (lengthMaze_Y)) {
				if (location[tx][ty]->getName() == "room")
					++count;
				if (location[tx][ty]->getName() == "empty")
					location[tx][ty] = Location::createObject(border);
			}
		}

		count = rand() % count + 1;
		for (int k = 0; k < 4; k++) {
			int tx = save_x + dx[k];
			int ty = save_y + dy[k];

			if (tx >= 0 && ty >= 0 && tx < lengthMaze_X && ty < lengthMaze_Y && (location[tx][ty]->getName() == "room")) {
				--count;
				if (count == 0) {
					breakWall(save_x, save_y, dx[k], dy[k]);
				}
			}
		}
	}
	// Конец построения лабиринта
}

// Делаем проход между комнатами
void World::breakWall(int x, int y, int dx, int dy) { 
	if (dx == -1) {
		((Room*)location[x][y])->setDirection(north);
		((Room*)location[x - 1][y])->setDirection(south);
	}
	else if (dx == 1) {
		((Room*)location[x][y])->setDirection(south);
		((Room*)location[x + 1][y])->setDirection(north);
	}
	else if (dy == 1) {
		((Room*)location[x][y])->setDirection(east);
		((Room*)location[x][y + 1])->setDirection(west);
	}
	else {
		((Room*)location[x][y])->setDirection(west);
		((Room*)location[x][y - 1])->setDirection(east);
	}
}

// Созадаем комнату в нашей локации 
void World::createRoom(int x, int y) {
	Location *createRoom = Location::createObject(room);
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, -1, 0, 1 };

	if (numberRoomWithChest == numberRoom)
		((Room*)createRoom)->addObjects(Object::createObject(chest));

	if (numberRoomWithKey == numberRoom)
		((Room*)createRoom)->addObjects(Object::createObject(key));

	if (x != 0 && y != 0) {
		if ((rand() % 12) == (2))
			((Room*)createRoom)->setDark(true);
		else
		if ((rand() % 10) == 6)
			((Room*)createRoom)->addMonster(Unit::createUnit(MONSTER, "Jungler"));
	}

	int numberOfItemsInRoom = rand() % 4;
	for (int j = 1; j <= numberOfItemsInRoom; j++) {
		int randomID = rand() % (5);
		((Room*)createRoom)->addObjects(Object::createObject(randomID));
	}

	location[x][y] = createRoom;
	++numberRoom;
}

int World::getHeight() {
	return lengthMaze_X;
}

int World::getWidth() {
	return lengthMaze_Y;
}

Location* World::getLocation() {
	return location[hero->getX()][hero->getY()];
}

Location* World::getLocation(int x, int y) {
	return location[x][y];
}

Hero* World::getHero() {
	return hero;
}

World::~World() {

	for (int i = 0; i < lengthMaze_X; i++) {
		for (int j = 0; j < lengthMaze_Y; j++) {
			delete location[i][j];
		}
	}
	
}