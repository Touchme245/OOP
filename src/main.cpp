#include <iostream>
#include "calculate.h"

int main(){
    int leftborder;
    int rightborder;
    std::cout << "Enter borders" << std::endl;
    std::cin >> leftborder >> rightborder;
    if (std::cin.fail()) {
        std::cerr << "Incorrect values" << std::endl;
        return 1;
    }
        int res = calculate(leftborder,rightborder);
        std::cout << res << std::endl;
    
}
