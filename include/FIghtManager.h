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

struct FightEvent
{
    NPC* attacker;
    NPC* defender;
};

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

    void add_event(FightEvent &&event)
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
                        events.pop();
                    }
                }

                if (event)
                {
                    try
                    {
                        bool fightStatus = false;
                        if (event->attacker->is_alive())     // no zombie fighting!
                            if (event->defender->is_alive()) // already dead!
                               
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
                                    event->defender->kill();
                                }
                    }
                    catch (...)
                    {
                        std::lock_guard<std::shared_mutex> lock(mtx);
                        events.push(*event);
                    }
                }
                else
                    std::this_thread::sleep_for(100ms);
            }
        }
    }

};