#pragma once
#include <iostream>
#include "Point.h"
// #include "Visitor.h"

class NPC{
    public:
        NPC(Point p);
        NPC();
        bool isClose(const NPC &other, size_t distance) const;
        Point getLocation();

        ~NPC() = default;
    protected:
        Point location;

    friend std::ostream &operator<<(std::ostream &os, NPC &npc);
};