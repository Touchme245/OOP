#include <iostream>
#include "Observer.h"
#include "NPC.h"

class ConsoleWriter :public Observer{
     void update(NPC* dead) override{
        std::cout << "New dead NPC with coords: " << dead->getLocation() << "\n";
     }
};