#pragma once
#include "Figure.h"

class Romb: public Figure{
    friend std::ostream& operator<<(std::ostream& os, const Romb& figure);
    friend std::istream& operator>>(std::istream& is, Romb& figure);
    public:
        Romb();
        Romb(const Point* points);
        Romb(const Romb& other);
        Romb(Romb&& other);

        virtual ~Romb() = default;

        virtual std::ostream& print(std::ostream& os) const override;
        virtual std::istream& read(std::istream& is) override;
        //std::string getFigureName() const;
        // Point* getPoints() const;

        virtual operator double() const override;
        virtual Point center() const override;

        Romb& operator =(const Romb& other);
        Romb& operator =(Romb&& other);
        bool operator ==(Romb& other);

        

        virtual Figure& operator=(const Figure&& other) override;
        virtual Figure& operator=(const Figure& other) override;
        virtual bool operator==(const Figure& other) override;
    private:
        std::string figureName = "Romb";
        virtual void fillPoints(const int pointsAmount,Point* res,const Point* data) override;
};

std::ostream& operator<<(std::ostream& os, const Romb& figure);
std::istream& operator>>(std::istream& is, Romb& figure);