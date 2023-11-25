#pragma once
#include "NPC.h"
#include "Observer.h"

class Observable{
    virtual void notify(NPC* dead) = 0;
    virtual void subscribe(Observer* obs) = 0;
    virtual void unSubscribe(Observer* obs) = 0;
};