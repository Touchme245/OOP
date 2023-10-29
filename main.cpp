#include <iostream>
#include "Trap.h"
#include "Point.h"
#include "Figure.h"
#include "Romb.h"
#include "Pentagon.h"
#include "FigureList.h"
#include "./src/lab0/Trap.cpp"
#include "./src/lab0/Romb.cpp"
#include "./src/lab0/Figure.cpp"
#include "./src/lab0/Point.cpp"
int main(){
    
    // Point<double>* TrapPoints = new Point<double>[4];
    // Point<double>* po = new Point<double>[4];
    // std::shared_ptr<Point<double>> TrapPoints = std::shared_ptr<Point<double>>(po);
    // TrapPoints.get()[0] = Point<double>{0,0};
    // TrapPoints.get()[1] = Point<double>{7,0};
    // TrapPoints.get()[2] = Point<double>{2,3};
    // TrapPoints.get()[3] = Point<double>{6,3};

    // // std::shared_ptr<Point<double>> TrapPoints1 = std::make_shared(TrapPoints);
    // // std::cout << "hi" << "\n";
    
    // Trap<double> trap{TrapPoints};
    // std::cout << "center: " << trap.center() << std::endl;
    // std::cout << "square " << (double) trap << std::endl;
    // std::cout << trap;
    // std::cout << "hi" << "\n";


    // std::shared_ptr<Point<double>> RombPoints = std::shared_ptr<Point<double>>(new Point<double>[4]);
    // RombPoints.get()[0] = Point<double>{0,0};
    // RombPoints.get()[1] = Point<double>{2,0};
    // RombPoints.get()[2] = Point<double>{2,2};
    // RombPoints.get()[3] = Point<double>{0,2};

    // // std::shared_ptr<Point<double>> TrapPoints1 = std::make_shared(TrapPoints);
    // // std::cout << "hi" << "\n";
    
    // Romb<double> romb{RombPoints};
    // std::cout << "center: " << romb.center() << std::endl;
    // std::cout << "square " << (double) romb << std::endl;
    // std::cout << romb;

    std::shared_ptr<Point<double>> PentPoints = std::shared_ptr<Point<double>>(new Point<double>[5]);
    PentPoints.get()[0] = Point<double>{0,0};
    PentPoints.get()[1] = Point<double>{2,0};
    PentPoints.get()[2] = Point<double>{22,2};
    PentPoints.get()[3] = Point<double>{3,12};
    PentPoints.get()[4] = Point<double>{5,8};

    // std::shared_ptr<Point<double>> TrapPoints1 = std::make_shared(TrapPoints);
    // std::cout << "hi" << "\n";
    
    Romb<double> pent{PentPoints};
    std::cout << "center: " << pent.center() << std::endl;
    std::cout << "square " << (double) pent << std::endl;
    std::cout << pent;

    // Point* Rombpoints = new Point[4];
    // Rombpoints[0] = Point{0,0};
    // Rombpoints[1] = Point{2,0};
    // Rombpoints[2] = Point{2,2};
    // Rombpoints[3] = Point{0,2};

    // Romb romb{Rombpoints};
    // std::cout << "center: " << romb.center() << std::endl;
    // std::cout << "square " << (double) romb << std::endl;
    // std::cout << romb;

    // std::cout << "hi" << "\n";
    // Point* PentagonPoints = new Point[5];
    // PentagonPoints[0] = Point{0,0};
    // PentagonPoints[1] = Point{2,0};
    // PentagonPoints[2] = Point{22,4};
    // PentagonPoints[3] = Point{3,12};
    // PentagonPoints[4] = Point{5,8};
    // Pentagon pentagon{PentagonPoints};
    // std::cout << "center: " << pentagon.center() << std::endl;
    // std::cout << "square " << (double) pentagon << std::endl;
//     std::cout << pentagon;

    // FigureList list;
    // Figure* pentagon = Pentagon::create(PentagonPoints);
    // list.push_back(pentagon);
    // list.push_back(dynamic_cast<Figure*>(new Trap(TrapPoints)));
    // list.push_back(dynamic_cast<Figure*>(new Romb(Rombpoints)));
    // for (int i = 0; i < list.getSize(); ++i){
    //      std::cout << list[i]->center() << "\n";
    //     std::cout << list[i]->getFigureName() << "\n";
    // }
    // list.remove(1);
    //  for (int i = 0; i < list.getSize(); ++i){
    //     std::cout << list[i]->center() << "\n";
    //     std::cout << list[i]->getFigureName() << "\n";
    // }

    
    
}