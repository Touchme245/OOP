#include "FigureList.h"
#include "Figure.h"

template<class T> FigureList<T>::FigureList(){
    size = 0;
    capacity = 10;
    figures = std::shared_ptr<std::shared_ptr<T>> (new std::shared_ptr<T>[capacity]);
}

template<class T> FigureList<T>::~FigureList(){
    size = 0;
    capacity = 0;
    // for (int i = 0;i < size; ++i){
    //     delete figures[i];
    // }
    // delete[] figures;
    // figures = nullptr;
}

template<class T> void FigureList<T>::push_back(std::shared_ptr<T> figure){
    if (size + 2 > capacity){
        capacity *= 2;
        std::shared_ptr<std::shared_ptr<T>> newFigures = std::shared_ptr<std::shared_ptr<T>> (new std::shared_ptr<T>[capacity]);;
        for (int i = 0; i < size; ++i){
            newFigures[i] = figures[i];
        }
        figures = newFigures;
    }

    figures[size++] = figure;

}

 template<class T> std::shared_ptr<T> FigureList<T>::operator [](const int index) const{
    if (index >= size || index < 0){
        throw std::invalid_argument("Invalid index");
    }
    return figures[index];
 }

template<class T> void FigureList<T>::remove(int index){
    if (index >= size || index < 0){
        throw std::invalid_argument("Invalid index");
    }
    for (int i = index; i < size; ++i){
        // delete figures[i];
        figures[i] = figures[i+1];
    }
    size--;
}

template<class T> int FigureList<T>::getSize() const {
    return size;
}
