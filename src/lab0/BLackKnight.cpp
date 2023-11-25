#include "BlackKnight.h"

BlackKnight::BlackKnight(){
    this->location = {0,0};
}

BlackKnight::BlackKnight(Point p){
    this->location = p;
}

std::ostream &operator<<(std::ostream &os, BlackKnight &blackKnight)
{
    os << "blackKnight: " << static_cast<NPC *>(&blackKnight) << std::endl;
    return os;
}

// void BlackKnight::accept(Visitor visitor){
//     visitor.visit(*this);
// }