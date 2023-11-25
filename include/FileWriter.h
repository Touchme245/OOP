#include <iostream>
#include <fstream>
#include "Observer.h"
#include "NPC.h"


class ConsoleWriter :public Observer{
    void update(NPC* dead) override{
        std::ofstream file("./logs.txt"); 
        if (file.is_open()) {
            file <<  "New dead NPC with coords: " << dead->getLocation() << "\n";
            file.close(); 
        } 
        else {
            std::cout << "Не удалось открыть файл." << std::endl;
        }
    }
};