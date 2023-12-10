#pragma once
#include <iostream>
#include <vector>
#include "NPC.h"
#include "Observer.h"
#include "Observable.h"
#include "algorithm"

class DeathAgregator : public Observable{
    private:
        std::vector<Observer*> observers;
    public:
        void notify(NPC* dead){
            for (auto obs : observers){
                obs->update(dead);
            }
        }
        void subscribe(Observer* obs){
            observers.push_back(obs);
        }
        void unSubscribe(Observer* obs){
            observers.erase(std::find(observers.begin(), observers.end(),obs));
        }
       
};