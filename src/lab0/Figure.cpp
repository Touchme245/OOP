#include "Figure.h"

template <class T> Figure<T>::Figure(std::string figureName){
    this->figureName = figureName;
}

template <class T> Figure<T>::~Figure(){
    figureName = "";
    // delete[] points;
    // points = nullptr;

}

template <class T> Figure<T>::Figure(){
    figureName = "";
    points = nullptr;
}

template <class T> std::shared_ptr<Point<T>> Figure<T>::getPoints() const{
    return points;
}

template <class T> std::string Figure<T>::getFigureName() const{
    return figureName;
}

template<class T> std::ostream& operator<<(std::ostream& os, const Figure<T>& figure){
    return figure.print(os);
}
template< class T>std::istream& operator>>(std::istream& is, Figure<T>& figure){
    return figure.read(is);
}

