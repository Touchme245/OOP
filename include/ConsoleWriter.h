#pragma once
#include <iostream>
#include "Observer.h"
#include "NPC.h"

class ConsoleWriter :public Observer{
     void update(NPC* dead) override{
        std::cout << dead->getName() << " погиб, он стоял в точке: " << dead->getLocation() << "\n";
     }
};