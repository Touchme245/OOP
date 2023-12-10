#pragma once
#include <Visitor.h>
#include "NPC.h"


class Sukuna : public NPC{
    public:
        Sukuna();
        Sukuna(Point p);
        bool accept(IVisitor & visitor) override;
    protected:
        int step_size = 200;
        int kill_distance = 160;
    friend std::ostream &operator<<(std::ostream &os, Sukuna &sukuna);
};