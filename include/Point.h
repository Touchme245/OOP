#pragma once
#include <iostream>
#include <math.h>
template<class T> class Point{
    template<class U> friend std::ostream& operator<<(std::ostream& os, const Point<U>& p);
    template<class U> friend std::istream& operator>>(std::istream& is, Point<U>& p);
    public:
        Point() = default;
        Point(const T x, const T y);
        Point(const Point<T>& other);
        Point(Point<T>&& other);
        ~Point() = default;
        T getX() const;
        T getY() const;
        void setX(T x);
        void setY(T y);
        Point<T> operator+(const Point<T>& other);
        Point<T> operator-(const Point<T>& other);
        bool operator==(const Point<T>& other) const;
        Point<T>& operator=(const Point<T>& other);
        Point<T>& operator=(Point<T>&& other);
        void print();
        

    private:
        T x;
        T y;
};
template<typename T>
std::ostream& operator<<(std::ostream& os, const Point<T>& p);
template<typename T>
std::istream& operator>>(std::istream& is, Point<T>& p);
template<typename T>
double dot(const Point<T>& p1, const Point<T>& p2);
template<typename T>
double abs(const Point<T>& p1);
template<typename T>
double cos(const Point<T>& p1, const Point<T>& p2);
template<typename T>
bool isParalel(const Point<T>& p1, const Point<T>& p2);
template<typename T>
Point<T> intersection(const Point<T>& p1, const Point<T>& p2);