#include "Location.h"
#include "Room.h"
#include "Border.h"
#include "Empty.h"

using namespace model;

Location* Location::createObject(int id) {
	switch (id) {
	case room:
		return new Room();
	case border:
		return new Border();
	case empty:
		return new Empty();
	default:
		break;
	}
}

Location::~Location() {

}