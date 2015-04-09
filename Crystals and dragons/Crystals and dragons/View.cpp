#include "View.h"
#include "ConsoleColor.h"
using namespace view;
using namespace model;
using namespace std;

View::View(Model * model) {
	this->model = model;
	model->registerObserver(this);
	rowDialogue = 0;
	isDarkRoom = false;
}

void View::update(ActionType type) {
	switch (type) {
	case HeroMove:
		break;

	case UnknownCommand:
		dialogueHero[rowDialogue] = "  I don't understand the commands";
		++rowDialogue;
		break;

	case MonsterThrewHero:
		dialogueHero[rowDialogue] = "  I was thrown monster!";
		++rowDialogue;
		break;

	case MonsterBitHero:
		dialogueHero[rowDialogue] = "  Monster hurt me!";
		++rowDialogue;
		break;

	case HeroNotSeeMonster:
		dialogueHero[rowDialogue] = "  There is no one to fight!";
		++rowDialogue;
		break;

	case HeroInDarkRoom:
		isDarkRoom = true;
		break;

	case HeroSeeMonsterInRoom:
		dialogueHero[rowDialogue] = "  There is an evil " + model->getMonsters() + " in the room!";
		++rowDialogue;
		break;

	case HeroHitWall:
		dialogueHero[rowDialogue] = "  There is a wall!";
		++rowDialogue;
		break;

	case HeroHasNotItem:
		dialogueHero[rowDialogue] = "  I have no such item!";
		++rowDialogue;
		break;

	case HeroGetItem:
		break;

	case HeroEat:
		dialogueHero[rowDialogue] = "  Mmm yummy!";
		++rowDialogue;
		break;

	case LocationHasNotItem:
		dialogueHero[rowDialogue] = "  There is no such object";
		++rowDialogue;
		break;

	case HeroKilledMonster:
		dialogueHero[rowDialogue] = "  I killed the monster!";
		++rowDialogue;
		break;

	case HeroOpenChest:
		dialogueHero[rowDialogue] = "  I found the Holy Grail!";
		++rowDialogue;
		break;

	case HeroCanNotEat:
		dialogueHero[rowDialogue] = "  I can not eat it!";
		++rowDialogue;
		break;

	case HeroGetChest:
		dialogueHero[rowDialogue] = "  I can not take the chest!";
		++rowDialogue;
		break;

	default:
		break;
	}
}

void View::display() {
	system("cls");

	if (isDarkRoom) {
		cout << endl;
		cout << white << "---------------->  " << red << "Can't see anything in this dark place!" << endl;
		cout << endl;
		isDarkRoom = false;
	}
	else {
		cout << white << "You are in the room [" << yellow << model->getPositionHero_X() << white << "," << yellow << model->getPositionHero_Y() << white << "]" << endl;
		cout << "There are [" << yellow << model->getNumberOfDoors() << white << "] doors: " << yellow << model->getDirections() << endl;
		cout << white << "Items in the room: " << yellow << model->getItems() << endl;
		cout << green << "-----------------------------------" << endl;
		cout << blue << "Hero -> " << red << model->getNameHero() << endl;
		cout << blue << "Healt -> " << yellow << model->getHealtHero() << endl;
		cout << blue << "Money -> " << yellow << model->getNumberMoneyOfHero() << endl;
		cout << blue << "Equipment -> " << yellow << model->getEquipmentHero() << endl;
		cout << green << "***********************************" << endl;
	}

	for (int i = 0; i < rowDialogue; i++) {
		cout << endl;
		cout << white << "---------------->" << red << dialogueHero[i] << endl;
		cout << endl;
	}

	rowDialogue = 0;
}