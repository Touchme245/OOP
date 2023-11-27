#include "Sukuna.h"

Sukuna::Sukuna(){
    this->location = {0,0};
    this->name = "Sukuna";
}

Sukuna::Sukuna(Point p){
    this->location = p;
    this->name = "Sukuna";
}

std::ostream &operator<<(std::ostream &os, Sukuna &sukuna)
{
    os << "Sukuna: " << static_cast<NPC *>(&sukuna) << std::endl;
    return os;
}

bool Sukuna::accept(IVisitor &visitor) {
    return visitor.visit(*this);
}