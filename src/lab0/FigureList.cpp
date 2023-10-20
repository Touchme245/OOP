#include "FigureList.h"
#include "Figure.h"

FigureList::FigureList(){
    size = 0;
    capacity = 10;
    figures = new Figure[capacity];
}

FigureList::~FigureList(){
    size = 0;
    capacity = 0;
    delete[] figures;
    figures = nullptr;
}

void FigureList::push_back(Figure* figure){
    // для более удобного удаления
    if (size + 2 > capacity){
        capacity *= 2;
        newFigures = Figures[capacity];
        for (int i = 0; i < size; ++i){
            newFigures[i] = figures[i];
        }
        delete[] figures;
        figures = newFigures;
    }

    figures[size++] = figure;

}

void FigureList::remove(int index){
    if (index >= size){
        throw std::invalid_argument("Index cant be > size");
    }
    for (int i = index; i <= size; ++i){
        free figures[i];
        figures[i] = figures[i+1];
    }
}

Figure FigureList::getElem(int index){
    if (index >= size){
        throw std::invalid_argument("Index cant be > size");
    }
    return figures[index];
}