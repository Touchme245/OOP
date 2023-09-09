#include <iostream>
#include "calculate.h"

int main(){
    int a;
    int b;
    std::cout << "Введите границы" << std::endl;
    std::cin >> a >> b;
    if (std::cin.fail()) {
        std::cerr << "Incorrect values" << std::endl;
    }
    else{
        int res = calculate(a,b);
        std::cout << res << std::endl;
    }
    
}
