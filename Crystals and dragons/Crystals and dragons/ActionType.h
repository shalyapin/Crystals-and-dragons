#ifndef ACTION_TYPE_H
#define ACTION_TYPE_H

namespace model {
	enum ActionType {
		HeroMove = 1,
		HeroInDarkRoom,
		HeroSeeMonsterInRoom,
		HeroHasNotItem,
		HeroHitWall,
		HeroGetItem,
		HeroEat,
		LocationHasNotItem,
		HeroNotSeeMonster,
		HeroKilledMonster,
		MonsterThrewHero,
		MonsterBitHero,
		HeroOpenChest,
		HeroCanNotEat,
		HeroGetChest,
		UnknownCommand
	};
}

#endif