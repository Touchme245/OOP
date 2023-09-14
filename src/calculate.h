#include <iostream>
#pragma once
int calculate(int leftborder, int rightborder){
    
    int res  {0};
    for (int i {leftborder}; i <= rightborder; ++i){
        int tek_number {i};
        while (tek_number > 0){
            res += tek_number % 2;
            tek_number = tek_number / 2;

        }
        
    }
    return res;
}
