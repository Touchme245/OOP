// #pragma once
// #include "Figure.h"
// #include <memory>
// #include <vector>
// #include "NumberConcept.h"
// template<Number T> class FigureList{
//     private:
//         int size;
//         int capacity;
//         std::shared_ptr<std::shared_ptr<Figure<T>>> figures;
//     public:
//         FigureList();
//         ~FigureList();
//         void push_back(std::shared_ptr<Figure<T>> figure);
//         void remove(int index);
//         int getSize() const;
//         std::shared_ptr<Figure<T>> operator [](const int index) const;
// };