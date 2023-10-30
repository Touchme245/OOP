// #include "FigureList.h"
// #include "Figure.h"
// #include "NumberConcept.h"
// #include <memory>
// template<Number T> FigureList<T>::FigureList(){
//     this->size = 0;
//     this->capacity = 10;
    
//     // std::shared_ptr<std::shared_ptr<Figure<T>>> figures;
//     this->figures = std::shared_ptr<std::shared_ptr<Figure<T>>> (std::shared_ptr<Figure<T>>(Figure<T>*[this->capacity]));
   
// }

// template<Number T> FigureList<T>::~FigureList(){
//     this->size = 0;
//     this->capacity = 0;
//     // for (int i = 0;i < size; ++i){
//     //     delete figures[i];
//     // }
//     // delete[] figures;
//     // figures = nullptr;
// }

// template<Number T> void FigureList<T>::push_back(std::shared_ptr<Figure<T>> figure){
//     if (size + 2 > capacity){
//         capacity *= 2;
//         std::shared_ptr<std::shared_ptr<T>> newFigures = std::shared_ptr<std::shared_ptr<T>> (new std::shared_ptr<T>[capacity]);;
//         for (int i = 0; i < size; ++i){
//             newFigures.get().get()[i] = figures.get().get()[i];
//         }
//         figures = newFigures;
//     }

//     figures.get()[size++] = figure;

// }

//  template<Number T> std::shared_ptr<Figure<T>> FigureList<T>::operator [](const int index) const{
//     if (index >= size || index < 0){
//         throw std::invalid_argument("Invalid index");
//     }
//     return figures.get()[index];
//  }

// template<Number T> void FigureList<T>::remove(int index){
//     if (index >= size || index < 0){
//         throw std::invalid_argument("Invalid index");
//     }
//     for (int i = index; i < size; ++i){
//         // delete figures[i];
//         figures.get()[i] = figures.get()[i+1];
//     }
//     size--;
// }

// template<Number T> int FigureList<T>::getSize() const {
//     return size;
// }
