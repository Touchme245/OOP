#include <iostream>
#include "calculate.h"
int calculate(int leftborder, int rightborder){
    
    int res = 0;
    for (int i {leftborder}; i <= rightborder; ++i){
        int num = i;
        while (num > 0){
            res += num % 2;
            num = num / 2;

        }
        
    }
    return res;
}
