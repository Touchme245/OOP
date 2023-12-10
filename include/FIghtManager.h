#pragma once
#include <queue>
#include "NPC.h"
#include <optional>
#include <chrono>
#include "NPC.h"
#include "Visitor.h"
#include <thread>
#include <pthread.h>

using namespace std::chrono_literals;

typedef struct FightEvent
{
    // FightEvent(NPC* attacker, NPC* defender){
    //     this->attacker = attacker;
    //     this->defender = defender;
    // }
    NPC* attacker;
    NPC* defender;
} FightEvent;

class FightManager
{
private:
    DragonVisitor dragonVisitor;
    KnightVisitor knightVisitor;
    BlackKnightVisitor blackVisitor;
    SukunaVisitor sukunaVisitor;
    std::queue<FightEvent> events;
    std::shared_mutex mtx;

    FightManager() {}

public:
    static FightManager &get()
    {
        static FightManager instance;
        return instance;
    }

    void add_event(FightEvent event)
    {
        std::lock_guard<std::shared_mutex> lock(mtx);
        events.push(event);
    }

    void operator()()
    {
        while (true)
        {
            {
                std::optional<FightEvent> event;

                {
                    std::lock_guard<std::shared_mutex> lock(mtx);
                    if (!events.empty())
                    {
                        event = events.back();
                        //std::cout << "new " << event->attacker->getName() << " " << event->defender->getName() << "\n";
                        events.pop();
                    }
                }

                if (event)
                {
                    try
                    {   
                        //std::cout << "work "<< event->attacker->getName() << " " << event->defender->getName() << "\n";
                        // std::cout << "ril fight\n";
                        bool fightStatus = false;
                        if (event->attacker->is_alive()){
                            if (event->defender->is_alive()){
                                 if (event->attacker->getName() == "Dragon") {
                                    fightStatus = event->defender->accept(dragonVisitor);
                                } else if (event->attacker->getName() == "Knight") {
                                    fightStatus = event->defender->accept(knightVisitor);
                                } else if (event->attacker->getName() == "BlackKnight"){
                                    fightStatus = event->defender->accept(blackVisitor);
                                }
                                else{
                                    fightStatus = event->defender->accept(sukunaVisitor);
                                }
                                if (fightStatus) {
                                   // std::cout << "killing\n";
                                    event->defender->kill();
                                }
                            } 
                               
                        }     
                            
                    }
                    catch (...)
                    {
                        std::cout <<"hueta\n";
                        //std::lock_guard<std::shared_mutex> lock(mtx);
                        //events.push(*event);
                    }
                }
                //else
                    // std::this_thread::sleep_for(100ms);
            }
        }
    }

};