#pragma once
#include <iostream>
#include "Point.h"
#include <string>
#include "Visitor.h"


class IVisitor;

class NPC{
    public:
        NPC(Point p);
        NPC();
        bool isClose(const NPC* other, size_t distance) const;
        Point getLocation();
        virtual bool accept(IVisitor & visitor) = 0;
        std::string getName() const;

        ~NPC() = default;
    protected:
        std::string name;
        Point location;

    friend std::ostream &operator<<(std::ostream &os, NPC &npc);
};