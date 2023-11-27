#include "Knight.h"

Knight::Knight(){
    this->location = {0,0};
    this->name = "Knight";
}

Knight::Knight(Point p){
    this->location = p;
    this->name = "Knight";
}

std::ostream &operator<<(std::ostream &os, Knight &knight)
{
    os << "knight: " << static_cast<NPC *>(&knight) << std::endl;
    return os;
}

bool Knight::accept(IVisitor &visitor) {
    return visitor.visit(*this);
}