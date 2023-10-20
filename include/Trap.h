#pragma once
#include "Figure.h"
#include "Point.h"
#include "ValidationCompositor.h"

class Trap : public Figure{
    friend std::ostream& operator<<(std::ostream& os, const Trap& figure);
    friend std::istream& operator>>(std::istream& is, Trap& figure);
    public:
        Trap();
        Trap(const Point* points);
        Trap(const Trap& other);
        Trap(Trap&& other);

        std::ostream& print(std::ostream& os) const override final;
        std::istream& read(std::istream& is) override final;

        static Trap create(const Point* points);

        virtual ~Trap() = default;

        //std::string getFigureName() const;
        // Point* getPoints() const override;
        
        operator double() const override final;
        Point center() const override final; 

        Trap& operator =(const Trap& other);
        Trap& operator =(Trap&& other);
        bool operator ==(const Trap& other) const;

        Figure& operator=(const Figure&& other) override final;
        Figure& operator=(const Figure& other) override final;
        bool operator==(const Figure& other) override final;


     private:
        std::string figureName = "Trap";
        void fillPoints(const int pointsAmount,Point* res,const Point* data) override final;
};

std::ostream& operator<<(std::ostream& os, const Trap& figure);
std::istream& operator>>(std::istream& is, Trap& figure);