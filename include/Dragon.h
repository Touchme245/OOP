#pragma once
#include <Visitor.h>
#include "NPC.h"


class Dragon : public NPC{
    public:
        Dragon();
        Dragon(Point p);
        // bool accept(Visitor visitor, NPC* defender);

    friend std::ostream &operator<<(std::ostream &os, Dragon &dragon);
};