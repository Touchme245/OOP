#include <iostream>
#pragma once
int calculate(int a, int b){
    
    int res = 0;
    for (int i {a}; i <= b; ++i){
        int tmp = i;
        while (tmp > 0){
            res += tmp % 2;
            tmp = tmp / 2;

        }
        
    }
    return res;
}
