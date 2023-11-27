#pragma once
#include <Visitor.h>
#include "NPC.h"


class Sukuna : public NPC{
    public:
        Sukuna();
        Sukuna(Point p);
        bool accept(IVisitor & visitor) override;
    friend std::ostream &operator<<(std::ostream &os, Sukuna &sukuna);
};