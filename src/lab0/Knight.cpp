#include "Knight.h"

Knight::Knight(){
    this->location = {0,0};
}

Knight::Knight(Point p){
    this->location = p;
}

std::ostream &operator<<(std::ostream &os, Knight &knight)
{
    os << "knight: " << static_cast<NPC *>(&knight) << std::endl;
    return os;
}