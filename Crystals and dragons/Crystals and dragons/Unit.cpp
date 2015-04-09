#include "Unit.h"
#include "Hero.h"
#include "Monster.h"
#include "idUnits.h"
using namespace model;

Unit* Unit::createUnit(int idUnit, std::string name) {
	switch (idUnit) {
	case HERO:
		return new Hero(name);
	case MONSTER:
		return new Monster(name);
	default:
		break;
	}
}