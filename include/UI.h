#pragma once
#include <vector>
#include "NPCFabric.h"
#include "DeathAgregator.h"
#include <set>
#include "Visitor.h"
#include "ConsoleWriter.h"
#include "Sukuna.h"
#define WIGHT 500
#define HIGH 500


std::set<NPC*>  fight(const std::set<NPC*> &alive, int distance ){
    std::set<NPC*> deathNote;
    
    DragonVisitor dragonVisitor;
    KnightVisitor knightVisitor;
    BlackKnightVisitor blackVisitor;
    SukunaVisitor sukunaVisitor;
    
    for (const auto & attacker : alive) {
        for (const auto & defender : alive) {
            if (attacker != defender && attacker->isClose(defender, distance)) {
                bool fightStatus;
                if (attacker->getName() == "Dragon") {
                    fightStatus = defender->accept(dragonVisitor);
                } else if (attacker->getName() == "Knight") {
                    fightStatus = defender->accept(knightVisitor);
                } else if (attacker->getName() == "BlackKnight"){
                    fightStatus = defender->accept(blackVisitor);
                }
                else{
                    fightStatus = defender->accept(sukunaVisitor);
                }
                if (fightStatus) {
                    deathNote.insert(defender);
                }
            }
        }
    }

    return deathNote;
}



class UI{
    public:
        static void  handleUserInput(){
            srand(time(nullptr));
            int n;
            std::cout << "Введите количество NPC которые будут созданы: ";
            std::cin >> n;
            std::set<NPC*> alive;
            int isSukuna = std::rand() % 5;
            if (isSukuna == 3){
                Point p{std::rand() % HIGH, std::rand() % WIGHT};
                std::cout << "Sukuna joined battle\n";
                alive.insert(dynamic_cast<NPC*>(new Sukuna(p)));
                std::cout << "Domain expansion\n";
           }
            // std::set<NPC*>deathNote;
            DeathAgregator deathAgregator; 
            ConsoleWriter* writer = new ConsoleWriter(); 
            deathAgregator.subscribe(dynamic_cast<Observer* >(writer));

            for (int i =0; i < n; ++i){
                alive.insert(NPCFabric::createNPC(NpcType(std::rand() % 3 + 1), std::rand() % WIGHT, std::rand() % HIGH));

            }

            for (int distance = 20; (distance <= std::max(WIGHT, HIGH) && !alive.empty()); distance+=10){
                std::set<NPC*> deathNote = fight(alive,distance);
                for (NPC * dead : deathNote){
                    deathAgregator.notify(dead);
                    alive.erase(dead);
                }
            }
            std::cout << "Игра окончена\n";
            for (auto elem : alive){
                std::cout << elem->getName() << " пережил мясорубку находясь в точке " << elem->getLocation() << "\n";
            }

    }
};