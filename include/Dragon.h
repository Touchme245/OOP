#pragma once
#include <Visitor.h>
#include "NPC.h"


class Dragon : public NPC{
    public:
        Dragon();
        Dragon(Point p);
        bool accept(IVisitor & visitor) override;
    friend std::ostream &operator<<(std::ostream &os, Dragon &dragon);
};