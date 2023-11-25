#include "NPC.h"
#include "math.h"

NPC::NPC(Point p){
    this->location = p;
}

NPC::NPC(){
    this->location = {0, 0};   
}

bool NPC::isClose(const NPC &other, size_t distance) const
{
    if (std::pow(this->location.getX() - other.location.getX(), 2) + std::pow(this->location.getY() - other.location.getY(), 2) <= std::pow(distance, 2))
        return true;
    else
        return false;
}

std::ostream &operator<<(std::ostream &os, NPC &npc)
{
    os << npc.location;
    return os;
}

Point NPC::getLocation(){
    return this->location;
}

