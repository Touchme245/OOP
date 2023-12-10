#pragma once
#include "NPC.h"

class Knight : public NPC{
    public:
        Knight();
        Knight(Point p);
        bool accept(IVisitor & visitor) override;
    protected:
        int step_size = 20;
        int kill_distance = 20;

    friend std::ostream &operator<<(std::ostream &os, Knight &knight);
};