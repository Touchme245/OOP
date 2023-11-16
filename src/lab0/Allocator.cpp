// #include "Allocator.h"

// // template<typename T> Allocator<T>::Allocator(){
// //     this->capacity = 0;
    
// // }

// template<typename T> Allocator<T>::Allocator(size_t n){
//     this->capacity = n;
//     this->memory.reserve(n);
// }

// template<typename T> T* Allocator<T>::allocate(size_t n){
//     if (n > this->capacity){
//         throw std::bad_alloc();
//     }
//     this->capacity-=n;
//     return &this->memory[this->memory.size() - capacity -1];
    
// }

// template<typename T> void Allocator<T>::deallocate(T* p, size_t n){
//     this->capacity += n;
     
// }





