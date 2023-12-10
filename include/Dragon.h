#pragma once
#include <Visitor.h>
#include "NPC.h"


class Dragon : public NPC{
    public:
        Dragon();
        Dragon(Point p);
        bool accept(IVisitor & visitor) override;
    protected:
        int step_size = 10;
        int kill_distance = 50;
    friend std::ostream &operator<<(std::ostream &os, Dragon &dragon);
};