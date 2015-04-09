#include "Object.h"
#include "Sword.h"
#include "Chest.h"
#include "Gold.h"
#include "Meat.h"
#include "Water.h"
#include "Torchlight.h"
#include "Key.h"

using namespace model;

Object* Object::createObject(int randomID) {
	switch (randomID) {
	case sword:
		return new Sword();
	case torchlight:
		return new Torchlight();
	case water:
		return new Water();
	case meat:
		return new Meat();
	case gold:
		return new Gold();
	case chest:
		return new Chest();
	case key:
		return new Key();
	}
}