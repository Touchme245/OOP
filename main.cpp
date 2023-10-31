#include <iostream>
#include "Trap.h"
#include "Point.h"
#include "Figure.h"
#include "Romb.h"
#include "Pentagon.h"
#include "FigureList.h"
#include "./src/lab0/Trap.cpp"
#include "./src/lab0/Romb.cpp"
#include "./src/lab0/Pentagon.cpp"
#include "./src/lab0/Figure.cpp"
#include "./src/lab0/Point.cpp"
#include "./src/lab0/FigureList.cpp"
#include <string>
int main(){
    
    
    Point<double>* po = new Point<double>[4];
    std::shared_ptr<Point<double>> TrapPoints = std::shared_ptr<Point<double>>(po);
    TrapPoints.get()[0] = Point<double>{0,0};
    TrapPoints.get()[1] = Point<double>{7,0};
    TrapPoints.get()[2] = Point<double>{2,3};
    TrapPoints.get()[3] = Point<double>{6,3};

   
    Trap<double> trap{TrapPoints};
    std::cout << "center: " << trap.center() << std::endl;
    std::cout << "square " << (double) trap << std::endl;
    std::cout << trap;

    
    


    std::shared_ptr<Point<double>> RombPoints = std::shared_ptr<Point<double>>(new Point<double>[4]);
    RombPoints.get()[0] = Point<double>{0,0};
    RombPoints.get()[1] = Point<double>{2,0};
    RombPoints.get()[2] = Point<double>{2,2};
    RombPoints.get()[3] = Point<double>{0,2};

   
    
    Romb<double> romb{RombPoints};
    std::cout << "center: " << romb.center() << std::endl;
    std::cout << "square " << (double) romb << std::endl;
    std::cout << romb;

    std::shared_ptr<Point<double>> PentPoints = std::shared_ptr<Point<double>>(new Point<double>[5]);
    PentPoints.get()[0] = Point<double>{0,0};
    PentPoints.get()[1] = Point<double>{2,0};
    PentPoints.get()[2] = Point<double>{22,2};
    PentPoints.get()[3] = Point<double>{3,12};
    PentPoints.get()[4] = Point<double>{5,8};

   
    
    Pentagon<double> pent{PentPoints};
    std::cout << "center: " << pent.center() << std::endl;
    std::cout << "square " << (double) pent << std::endl;
    std::cout << pent;

   

    FigureList<Figure<double>*> list;
    
    
    list.push_back(dynamic_cast<Figure<double>*>(new Trap(TrapPoints)));
    list.push_back(dynamic_cast<Figure<double>*>(new Pentagon(PentPoints)));
    list.push_back(dynamic_cast<Figure<double>*>(new Romb(RombPoints)));
    
    list.remove(1);
     for (int i = 0; i < list.getSize(); ++i){
        std::cout << list[i]->center() << "\n";
        std::cout << list[i]->getFigureName() << "\n";
    }

    
    
}