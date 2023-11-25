#pragma once
#include "NPC.h"

class BlackKnight : public NPC{
    public:
        BlackKnight();
        BlackKnight(Point p);
        // bool accept(Visitor visitor);

    friend std::ostream &operator<<(std::ostream &os, BlackKnight &blackKnight);
};