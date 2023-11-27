#include "BlackKnight.h"

BlackKnight::BlackKnight(){
    this->location = {0,0};
    this->name = "BlackKnight";
}

BlackKnight::BlackKnight(Point p){
    this->location = p;
    this->name = "BlackKnight";
}

std::ostream &operator<<(std::ostream &os, BlackKnight &blackKnight)
{
    os << "blackKnight: " << static_cast<NPC *>(&blackKnight) << std::endl;
    return os;
}

bool BlackKnight::accept(IVisitor &visitor) {
    return visitor.visit(*this);
}