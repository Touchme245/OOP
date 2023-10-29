#pragma once
#include "Figure.h"
#include <memory>

template<class T> class FigureList{
    private:
        int size;
        int capacity;
        std::shared_ptr<std::shared_ptr<T>> figures;
    public:
        FigureList();
        ~FigureList();
        void push_back(std::shared_ptr<T> figure);
        void remove(int index);
        int getSize() const;
        std::shared_ptr<T> operator [](const int index) const;
};