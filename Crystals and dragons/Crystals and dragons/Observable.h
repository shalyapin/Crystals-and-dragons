#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "Observer.h"

class Observable {
public:
	virtual void registerObserver(Observer *observer) = 0;
	virtual void removeObserver(Observer *observer) = 0;
	virtual void notifyObservers(model::ActionType type) = 0;
};

#endif