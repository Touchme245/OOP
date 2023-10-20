#include "Trap.h"
#include "Point.h"
#include <iostream>
#include <ValidationCompositor.h>


Trap::Trap(){
    figureName = "Trap";
    points = new Point[4];
}
//Figure*
Trap Trap::create(const Point* points){
   //dynamic_cast<Figure*>
    return Trap{points};
}


Trap::Trap(const Point* points){
    figureName = "Trap";
    this->points = new Point[4];
    for (int i = 0; i < 4; ++i){
        this->points[i] = points[i];
    }

    ValidationCompositor validator;
    validator.validate(dynamic_cast<Figure &>(*this));

}

Trap::Trap(const Trap& other){
    this->points = new Point[4];
    for (int i = 0; i < 4; ++i){
        this->points[i] = points[i];
    }
}

Trap::Trap(Trap&& other){
    points = other.points;

    delete[] other.points;
    other.points = nullptr;
}

Trap& Trap::operator=(const Trap& other){
    this->points = new Point[4];
    for (int i = 0; i < 4; ++i){
        this->points[i] = other.points[i];
    }
    return *this;
}

Trap& Trap::operator=(Trap&& other){
    points = other.points;

    delete[] other.points;
    other.points = nullptr;

    return *this;
}

bool Trap::operator==(const Trap& other)const{
    for (int i = 0; i < 4;++i){
        int flag = 0;
        for (int j = 0; j < 4; ++j){
            if ((points[i].getX() == other.points[i].getX()) && (points[i].getY() == other.points[i].getY())){
                flag = 1;
            }
        }
        if (!flag){
            return false;
        }
    }
    return true;
}


// bool Trap::operator==(const Figure& other){
//     for (int i = 0; i < 4; ++i){
//         if (!(points[i] == other.getPoints()[i])){
//             return false;
//         }
//     }
//     return true;
// }
Figure& Trap::operator=(const Figure&& other){
    try{
        const Trap&& other_trap = dynamic_cast<const Trap&&>(other);
        return *this = other_trap;
    }
    catch(const std::bad_cast &e){
        throw std::invalid_argument("exepted Trap");

    }
    
}
Figure& Trap::operator=(const Figure& other){
    try{
        const Trap& other_trap = dynamic_cast<const Trap&>(other);
        return *this = other_trap;
    }
    catch(const std::bad_cast &e){
        throw std::invalid_argument("exepted Trap");

    }
}

bool Trap::operator==(const Figure& other){
    try{
        const Trap& other_trap = dynamic_cast<const Trap&>(other);
        return *this== other_trap;
    }
    catch(const std::bad_cast &e){
        return false;
    }
}

// std::string Trap::getFigureName() const{
//     return figureName;
// }

// Point* Trap::getPoints() const{
//     return points;
// }

Point Trap::center()const{
    double Xsum = 0;
    double Ysum = 0;
    for(int i = 0; i < 4; ++i){
        Xsum += points[i].getX();
        Ysum += points[i].getY();
    }
    Point center;
    center.setX(Xsum / 4); 
    center.setY(Ysum / 4);

    return center;

}

Trap::operator double() const{
    double s = 0;
    for (int i = 0; i < 4; i++) {
        s += points[i].getX() * points[(i + 1) % 4].getY() - points[i].getY() * points[(i + 1) % 4].getX();
    }
    return fabs(s / 2);
}

void Trap::fillPoints(const int pointsAmount,Point* res,const Point* data){
     for (int i = 0; pointsAmount < 4; ++ i){
        res[i] = data[i];
    }
}

std::ostream& operator<<(std::ostream& os, const Trap& figure){
    return figure.print(std::cout);
}
std::istream& operator>>(std::istream& is, Trap& figure){
    return figure.read(std::cin);
}

std::ostream& Trap::print(std::ostream& os) const{
    for (int i = 0; i < 4; ++i){
        os << points[i] << "\n";
    }
    os << "\n";
    return os;
}
std::istream& Trap::read(std::istream& is){
    for (int i = 0; i < 4; ++i){
        is >> points[i];
    }
    return is;
}

