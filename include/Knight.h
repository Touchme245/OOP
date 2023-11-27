#pragma once
#include "NPC.h"

class Knight : public NPC{
    public:
        Knight();
        Knight(Point p);
        bool accept(IVisitor & visitor) override;

    friend std::ostream &operator<<(std::ostream &os, Knight &knight);
};