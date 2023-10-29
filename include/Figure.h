#pragma once
#include <string>
#include "Point.h"
#include <memory>

template <class T> class Figure{
    template<class U> friend std::ostream& operator<<(std::ostream& os, const Figure<U>& figure);
    template<class U> friend std::istream& operator>>(std::istream& is, Figure<U>& figure);
    protected:
    Figure();
    Figure(std::string figureName);
    virtual std::ostream& print(std::ostream& os) const = 0;
    virtual std::istream& read(std::istream& is) = 0;

    public:
        virtual ~Figure();    
        virtual operator double() const = 0;
        virtual Point<T> center() const = 0;
        virtual bool operator==(const Figure<T>& other)=0;
        virtual Figure<T>& operator=(const Figure<T>&& other)=0;
        virtual Figure<T>& operator=(const Figure<T>& other)=0;
        virtual std::string getFigureName() const;
        virtual std::shared_ptr<Point<T>> getPoints() const ;
    protected:
        std::string figureName;
        std::shared_ptr<Point<T>> points;
        virtual void fillPoints(const int pointsAmount,Point<T>* res,const Point<T>* data) = 0;
    
};
template<typename T>
std::ostream& operator<<(std::ostream& os, const Figure<T>& figure);
template<typename T>
std::istream& operator>>(std::istream& is, Figure<T>& figure);