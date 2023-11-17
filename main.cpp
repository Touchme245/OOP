#include <iostream>
#include <map>
#include "./src/lab0/Aloctr.cpp"
#include "./src/lab0/Vector2.cpp"
// #include "Utils.h"


// using map_type_with_allocator =
//     std::map<int, int, std::less<int>, mai::allocator<std::pair<const int, int>, 10>>;

int main(){
    std::map<int, int, std::less<int>, mai::allocator<std::pair<const int, int>, 10>> map;

    map.insert(std::pair<int, int>(0, 1));
    map.insert(std::pair<int, int>(1, 1));
    map.insert(std::pair<int, int>(2, 2));
    // fill_map<9>(map);
    for (auto p : map)
        std::cout << p.first << " " << p.second << std::endl;

        std::cout << "-----------------------------------------\n";

    MyVector::Vector<int, mai::allocator<int, 10>> vect{};
    for (int i = 0; i < 10; ++i){
        vect.push_back(i);
    }

    for (auto e : vect){
        std::cout << e << "\n";
    }
    
}