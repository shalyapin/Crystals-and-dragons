#ifndef WORLD_H
#define WORLD_H

#include "Hero.h"
#include "Room.h"
#include "Empty.h"
#include "Border.h"

namespace model {
	class World {
	private:
		static const int width = 20;
		static const int height = 20;
		int lengthMaze_X;
		int lengthMaze_Y;
		int numberOfRooms;
		Location *location[width][height];
		Hero *hero;
		void generateWorld();
		void createRoom(int x, int y);
		void breakWall(int x, int y, int dx, int dy);
		int numberRoomWithChest;
		int numberRoomWithKey;
		int numberRoom;
	public:
		World();
		World(int n, Hero *myHero);
		~World();
		Hero* getHero();
		Location* getLocation();
		Location* getLocation(int x, int y);
		int getWidth();
		int getHeight();
	};
}

#endif