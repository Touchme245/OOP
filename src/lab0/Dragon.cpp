#include "Dragon.h"

Dragon::Dragon(){
    this->location = {0,0};
}

Dragon::Dragon(Point p){
    this->location = p;
}

std::ostream &operator<<(std::ostream &os, Dragon &dragon)
{
    os << "dragon: " << static_cast<NPC *>(&dragon) << std::endl;
    return os;
}

// bool Dragon::accept(Visitor visitor, NPC* defender){
//     return visitor.visit(this, defender);
// }