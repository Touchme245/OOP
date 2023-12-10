#pragma once
#include <vector>
#include "NPCFabric.h"
#include "DeathAgregator.h"
#include <set>
#include "Visitor.h"
#include "ConsoleWriter.h"
#include "Sukuna.h"
#include <thread>
#include <pthread.h>
#include <queue>
#include <optional>
#include "FIghtManager.h"
using namespace std::chrono_literals;
#define WIGHT 500
#define HIGH 500
std::mutex print_mutex;


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
            //std::cout << isSukuna << "\n";
           // std::this_thread::sleep_for(5s);
            DeathAgregator deathAgregator; 
            ConsoleWriter* writer = new ConsoleWriter(); 
            deathAgregator.subscribe(dynamic_cast<Observer* >(writer));

            for (int i =0; i < n; ++i){
                alive.insert(NPCFabric::createNPC(NpcType(std::rand() % 3 + 1), std::rand() % WIGHT, std::rand() % HIGH));

            }

          
            std::thread fight_thread(std::ref(FightManager::get()));

            
            std::thread move_thread([&alive]()
                            {
            while (true){
                // move phase
                for (NPC* npc : alive){
                        if(npc->is_alive()){
                            int shift_x = std::rand() % 20 - 10;
                            int shift_y = std::rand() % 20 - 10;
                            npc->move(shift_x, shift_y, HIGH, WIGHT);
                        }
                }
                // lets fight
                
                for (NPC* npc : alive)
                    for (NPC* other : alive)
                        if (other != npc)
                            if (npc->is_alive()){
                                if (other->is_alive()){
                                    FightEvent ev{npc,other};
                                    if (npc->isClose(other, npc->getKillDistance())){
                                         FightManager::get().add_event(ev);
                                    }
                               
                                }
                            
                            }
                            

                
            } });

    while (true){
        const int grid{20}, step_x{HIGH / grid}, step_y{WIGHT / grid};
        {
            std::array<char, grid * grid+ 100> fields{0};
            for (NPC* npc : alive){
                Point p = npc->getLocation();
                int i = p.getX() / step_x;
                int j = p.getY() / step_y;
                if (npc->is_alive()){
                    std::string name = npc->getName();
                    if (name == "Dragon"){
                        fields[i + grid * j] = 'D';
                    }
                    else if (name == "Knight"){
                        fields[i + grid * j] = 'K';
                    }
                    else if (name == "BlackKnight"){
                        fields[i + grid * j] = 'B';
                    }
                    else if (name == "Sukuna"){
                        fields[i+ grid * j] = 'S';
                    }
                }
                else{
                    fields[i + grid * j] = '.';
                }
                
                
            }

            std::lock_guard<std::mutex> lck(print_mutex);
            for (int j = 0; j < grid; ++j){
                for (int i = 0; i < grid; ++i){
                    char c = fields[i + j * grid];
                    if (c != 0)
                        std::cout << "[" << c << "]";
                    else
                        std::cout << "[ ]";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
        std::this_thread::sleep_for(10ms);
    };
        
           move_thread.join();
            fight_thread.join();
        
        
    }
};