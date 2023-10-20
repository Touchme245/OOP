#pragma once
#include "Figure.h"


class FigureList{
    private:
        int size;
        int capacity;
        Figure* figures;
    public:
        FigureList();
        ~FigureList();
        void push_back(Figure* figure);
        void remove(int index);
        Figure getElem(int index);
}