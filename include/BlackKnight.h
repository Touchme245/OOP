#pragma once
#include "NPC.h"

class BlackKnight : public NPC{
    public:
        BlackKnight();
        BlackKnight(Point p);
        bool accept(IVisitor & visitor) override;
    protected:
        int step_size = 20;
        int kill_distance = 20;

    friend std::ostream &operator<<(std::ostream &os, BlackKnight &blackKnight);
};