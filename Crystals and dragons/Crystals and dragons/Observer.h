#ifndef OBSERVER_H
#define OBSERVER_H

#include "ActionType.h"

class Observer {
public:
	virtual void update(model::ActionType type) = 0;
};

#endif