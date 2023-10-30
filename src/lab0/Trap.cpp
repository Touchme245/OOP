#include "Trap.h"
#include "Point.h"
#include <iostream>
// #include <ValidationCompositor.h>


template<Number T> Trap<T>::Trap(){
    this->figureName = "Trap";
    this->points = std::shared_ptr<Point<T>>(new Point<T>[4]);
}
//Figure*
template<Number T> Trap<T> Trap<T>::create(const std::shared_ptr<Point<T>> points){
   //dynamic_cast<Figure*>
    return Trap<T>{points};
}


template<Number T> Trap<T>::Trap(const std::shared_ptr<Point<T>> points){
    this->figureName = "Trap";
    this->points = std::shared_ptr<Point<T>>(new Point<T>[4]);
    for (int i = 0; i < 4; ++i){
        this->points.get()[i] = points.get()[i];
    }

    ValidationCompositor<T> validator;
    validator.validate(dynamic_cast<Figure<T> &>(*this));

}

template<Number T> Trap<T>::Trap(const Trap<T>& other){
    this->points = std::shared_ptr<Point<T>>(new Point<T>[4]);
    for (int i = 0; i < 4; ++i){
        this->points.get()[i] = other.points.get()[i];
    }
}

template<Number T> Trap<T>::Trap(Trap<T>&& other){
    this->points = other.points;

    //delete[] other.points;
    //other.points = nullptr;
}

template<Number T> Trap<T>& Trap<T>::operator=(const Trap<T>& other){
    this->points = std::shared_ptr<Point<T>>(new Point<T>[4]);
    for (int i = 0; i < 4; ++i){
        this->points.get()[i] = other.points.get()[i];
    }
    return *this;
}

template<Number T> Trap<T>& Trap<T>::operator=(Trap<T>&& other){
    this->points = other.points;

    //delete[] other.points;
    //other.points = nullptr;

    return *this;
}

template<Number T> bool Trap<T>::operator==(const Trap<T>& other)const{
    for (int i = 0; i < 4;++i){
        int flag = 0;
        for (int j = 0; j < 4; ++j){
            if ((this->points.get()[i].getX() == other.points.get()[i].getX()) && (this->points.get()[i].getY() == other.points.get()[i].getY())){
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
template<Number T> Figure<T>& Trap<T>::operator=(const Figure<T>&& other){
    try{
        const Trap<T>&& other_trap = dynamic_cast<const Trap<T>&&>(other);
        return *this = other_trap;
    }
    catch(const std::bad_cast &e){
        throw std::invalid_argument("exepted Trap");

    }
    
}
template<Number T>Figure<T>& Trap<T>::operator=(const Figure<T>& other){
    try{
        const Trap<T>& other_trap = dynamic_cast<const Trap<T>&>(other);
        return *this = other_trap;
    }
    catch(const std::bad_cast &e){
        throw std::invalid_argument("exepted Trap");

    }
}

template<Number T> bool Trap<T>::operator==(const Figure<T>& other){
    try{
        const Trap<T>& other_trap = dynamic_cast<const Trap<T>&>(other);
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

template<Number T> Point<T> Trap<T>::center()const{
    T Xsum = 0;
    T Ysum = 0;
    for(int i = 0; i < 4; ++i){
        Xsum += this->points.get()[i].getX();
        Ysum += this->points.get()[i].getY();
    }
    Point<T> center;
    center.setX(Xsum / 4); 
    center.setY(Ysum / 4);

    return center;

}

template<Number T> Trap<T>::operator double() const{
    T s = 0;
    for (int i = 0; i < 4; i++) {
        s += this->points.get()[i].getX() * this->points.get()[(i + 1) % 4].getY() - this->points.get()[i].getY() * this->points.get()[(i + 1) % 4].getX();
    }
    return fabs(s / 2);
}

template<Number T> void Trap<T>::fillPoints(const int pointsAmount,Point<T>* res,const Point<T>* data){
     for (int i = 0; i < pointsAmount; ++ i){
        res[i] = data[i];
    }
}

template<Number T> std::ostream& operator<<(std::ostream& os, const Trap<T>& figure){
    return figure.print(std::cout);
}

template<Number T> std::istream& operator>>(std::istream& is, Trap<T>& figure){
    return figure.read(std::cin);
}

template<Number T> std::ostream& Trap<T>::print(std::ostream& os) const{
    for (int i = 0; i < 4; ++i){
        os << this->points.get()[i] << "\n";
    }
    return os;
}
template<Number T> std::istream& Trap<T>::read(std::istream& is){
    for (int i = 0; i < 4; ++i){
        is >> this->points.get()[i];
    }
    return is;
}

