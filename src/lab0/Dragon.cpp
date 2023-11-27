#include "Dragon.h"

Dragon::Dragon(){
    this->location = {0,0};
    this->name = "Dragon";
}

Dragon::Dragon(Point p){
    this->location = p;
    this->name = "Dragon";
}

std::ostream &operator<<(std::ostream &os, Dragon &dragon)
{
    os << "dragon: " << static_cast<NPC *>(&dragon) << std::endl;
    return os;
}

bool Dragon::accept(IVisitor &visitor) {
    return visitor.visit(*this);
}