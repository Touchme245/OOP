#pragma once
#include "NPC.h"

class Observer{
    public:
        virtual void update(NPC* dead) = 0;
};