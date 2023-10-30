#pragma once
#include "Figure.h"
#include "Point.h"
#include "ValidationCompositor.h"
#include <memory>
#include "NumberConcept.h"

template<Number T> class Trap : public Figure<T>{
    template<Number U> friend std::ostream& operator<<(std::ostream& os, const Trap<U>& figure);
    template<Number U> friend std::istream& operator>>(std::istream& is, Trap<U>& figure);
    public:
        Trap();
        Trap(const std::shared_ptr<Point<T>> points);
        Trap(const Trap<T>& other);
        Trap(Trap<T>&& other);

        std::ostream& print(std::ostream& os) const override final;
        std::istream& read(std::istream& is) override final;

        static Trap<T> create(const std::shared_ptr<Point<T>> points);

        virtual ~Trap() = default;
        
        operator double() const override final;
        Point<T> center() const override final; 

        Trap<T>& operator =(const Trap<T>& other);
        Trap<T>& operator =(Trap<T>&& other);
        bool operator ==(const Trap<T>& other) const;

        Figure<T>& operator=(const Figure<T>&& other) override final;
        Figure<T>& operator=(const Figure<T>& other) override final;
        bool operator==(const Figure<T>& other) override final;


     private:
        void fillPoints(const int pointsAmount,Point<T>* res,const Point<T>* data) override final;
};
template<Number T>
std::ostream& operator<<(std::ostream& os, const Trap<T>& figure);
template<Number T>
std::istream& operator>>(std::istream& is, Trap<T>& figure);