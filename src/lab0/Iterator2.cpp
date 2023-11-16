// #include "Iterator2.h"
// #include "Vector2.h"
// namespace MyVector {


// template<typename Vector> VectorIterator<Vector>::VectorIterator(PointerType ptr){
//     this->ptr = ptr;
// }

// template<typename Vector> VectorIterator& VectorIterator<Vector>::operator++(){
//     this->ptr++;
//     return *this;
// }

// template<typename Vector> VectorIterator VectorIterator<Vector>::operator++(int){
//     VectorIterator itr = *this;
//     ++(*this);
//     return itr;
// }

// template<typename Vector> VectorIterator& VectorIterator<Vector>::operator--(){
//     this->ptr--;
//     return *this;
// }

// template<typename Vector> VectorIterator VectorIterator<Vector>::operator--(int){
//     VectorIterator itr = *this;
//     --(*this);
//     return itr;
// }

// template<typename Vector> Vector::ValueType& VectorIterator<Vector>::operator[](int index){
//     return *(this->ptr + index);
// }

// template<typename Vector> Vector::ValueType* VectorIterator<Vector>::operator->(){
//     return this->ptr;
// }

// template<typename Vector> Vector::ValueType& VectorIterator<Vector>::operator*(){
//     return *this->ptr;
// }

// template<typename Vector> bool VectorIterator<Vector>::operator==(const VectorIterator& other)const {
//     return this->ptr == other.ptr;
// }

// template<typename Vector> bool VectorIterator<Vector>::operator!=(const VectorIterator& other)const {
//     return this->ptr != other.ptr;
// }

















// }