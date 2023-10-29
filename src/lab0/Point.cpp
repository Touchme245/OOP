#include "Point.h"
#include <iostream>
#include <math.h>
const double EPS = 1e-9;

template<class T> Point<T>::Point(const T x,const T y){
    this->x = x;
    this->y = y;
}

template<class T> Point<T>::Point(const Point<T>& other){
    x = other.x;
    y = other.y;
}

template<class T> Point<T>::Point(Point<T>&& other){
    x = other.x;
    y = other.y;

    //other.x = 0;
   // other.y = 0;

}
template<class T> T Point<T>::getX() const{
    return x;
}

template<class T> T Point<T>::getY() const{
    return y;
}

template<class T> void Point<T>::setX(T x){
    this->x = x;
}

template<class T> void Point<T>::setY(T y){
    this->y = y;
}

template<class T> Point<T> Point<T>::operator+(const Point<T>& other){
    // x += other.x;
    // y += other.y;
    return Point<T>(x + other.x, y + other.y);
}

template<class T> Point<T> Point<T>::operator-(const Point<T>& other){
    // x -= other.x;
    // y -= other.y;
    return Point<T>(x - other.x, y - other.y);
}

template<class T> bool Point<T>::operator==(const Point<T>& other)const {
    return (std::abs(x - other.x) < EPS) && (std::abs(y - other.y) < EPS);
}

template<class T> Point<T>& Point<T>::operator=(const Point<T>& other){
    x = other.x;
    y = other.y;
    return *this;
}

template<class T> Point<T>& Point<T>::operator=(Point<T>&& other){
    x = other.x;
    y = other.y;

   // other.x = 0;
   // other.y = 0;
    return *this;
}

template<typename T> void Point<T>::print(){
    std::cout << "Point(x: " << x << ", y: " << y << ")" << std::endl;
}

template<typename T> double dot(const Point<T>& p1, const Point<T>& p2){
    return p1.getX() * p2.getX() + p1.getY() * p2.getY();
}
template<typename T> double abs(const Point<T>& p1){
    return sqrt(p1.getX() * p1.getX() + p1.getY() * p1.getY());
}
template<typename T> double cos(const Point<T>& p1, const Point<T>& p2){
    return dot(p1,p2) / (abs(p1) * abs(p2));
}

template<typename T> bool isParalel(const Point<T>& p1, const Point<T>& p2){
    if (fabs(fabs(cos(p1, p2)) -1) <= EPS){
        return true;
    }
    return false;
}


template<typename T> std::ostream& operator<<(std::ostream& os, const Point<T>& p){
    os << p.x << " " << p.y;
    return os;
}

template<typename T> std::istream& operator>>(std::istream& is, Point<T>& p){
    is >> p.x >> p.y;
    return is;
}