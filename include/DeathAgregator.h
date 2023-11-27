#pragma once
#include <iostream>
#include <vector>
#include "NPC.h"
#include "Observer.h"
#include "Observable.h"

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
            int flag = 0;
            for (int i =0; i < observers.size()-1; ++i){
                if (observers[i] == obs){
                    flag = 1;
                }
                if (flag){
                    observers[i] = observers[i+1];
                }
            }
            observers.resize(observers.size() -1);
        }
       
};