#pragma once
#include <iostream>
#include "Point.h"
#include <string>
#include "Visitor.h"
#include <shared_mutex>
#include <memory>


class IVisitor;

class NPC{
    public:
        NPC(Point p);
        NPC();
        bool isClose(const NPC* other, size_t distance);
        Point getLocation();
        virtual bool accept(IVisitor & visitor) = 0;
        std::string getName() const;
        
        void move(int shift_x, int shift_y, int max_x, int max_y);
        bool is_alive();
        void kill();
        int getKillDistance();
        ~NPC() = default;
    protected:
        std::mutex mtx;
        std::string name;
        Point location;
        int step_size = 0;
        int kill_distance = 0;
        bool alive{true};

    friend std::ostream &operator<<(std::ostream &os, NPC &npc);
};