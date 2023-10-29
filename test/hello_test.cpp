// #include <gtest/gtest.h>
// #include "Point.h"
// #include "Trap.h"
// #include "Romb.h"
// #include "Pentagon.h"
// #include "ArrayValidation.h"
// #include "FigureList.h"


// TEST(TrapPointConstructor, BasicAssertions) {
//     // arrange 
//     Point* TrapPoints = new Point[4];
//     TrapPoints[0] = Point{0,0};
//     TrapPoints[1] = Point{7,0};
//     TrapPoints[2] = Point{2,3};
//     TrapPoints[3] = Point{6,3};
 
//     // act
//     Trap trap{TrapPoints};

//     // assert
//     bool res = validateArray(TrapPoints, trap.getPoints(), 4);
//     EXPECT_EQ(res, true);
// }

// TEST(TrapFabric, BasicAssertions) {
//     // arrange 
//     Point* TrapPoints = new Point[4];
//     TrapPoints[0] = Point{0,0};
//     TrapPoints[1] = Point{7,0};
//     TrapPoints[2] = Point{2,3};
//     TrapPoints[3] = Point{6,3};
 
//     // act
//     Trap trap = Trap::create(TrapPoints);

//     // assert
//     bool res = validateArray(TrapPoints, trap.getPoints(), 4);
//     EXPECT_EQ(res, true);
// }



// TEST(TrapOppositesSidesArentParralelValueExeption, BasicAssertions) {
//     // arrange 
//     Point* TrapPoints = new Point[4];
//     TrapPoints[0] = Point{2,4};
//     TrapPoints[1] = Point{4,8};
//     TrapPoints[2] = Point{2,3};
//     TrapPoints[3] = Point{6,3};

//     // assert
//     EXPECT_THROW(Trap trap{TrapPoints};, std::invalid_argument);

// }

// TEST(TrapSideZeroLenValueExeption, BasicAssertions) {
//     // arrange 
//     Point* TrapPoints = new Point[4];
//     TrapPoints[0] = Point{2,2};
//     TrapPoints[1] = Point{2,2};
//     TrapPoints[2] = Point{2,3};
//     TrapPoints[3] = Point{6,3};

//     // assert
//     EXPECT_THROW(Trap trap{TrapPoints};, std::invalid_argument);

// }

// TEST(TrapCenterConstructor, BasicAssertions) {
//     // arrange 
//     Point* TrapPoints = new Point[4];
//     TrapPoints[0] = Point{0,0};
//     TrapPoints[1] = Point{7,0};
//     TrapPoints[2] = Point{2,3};
//     TrapPoints[3] = Point{6,3};
//     Trap trap{TrapPoints};
//     Point expectedCenter = Point{3.75, 1.5};
//     // act
//     Point center = trap.center();

//     // assert
//    EXPECT_DOUBLE_EQ(center.getX(), expectedCenter.getX());
//    EXPECT_DOUBLE_EQ(center.getY(), expectedCenter.getY());
// }

// TEST(TrapSquareConstructor, BasicAssertions) {
//     // arrange 
//     Point* TrapPoints = new Point[4];
//     TrapPoints[0] = Point{0,0};
//     TrapPoints[1] = Point{7,0};
//     TrapPoints[2] = Point{2,3};
//     TrapPoints[3] = Point{6,3};
//     Trap trap{TrapPoints};
//     double expectedSquare = 4.5;
//     // act
    
//     double square = (double) trap;

//     // assert
//     EXPECT_DOUBLE_EQ(square, expectedSquare);
// }

// TEST(RombPointConstructor, BasicAssertions) {
//     // arrange 
//     Point* Rombpoints = new Point[4];
//     Rombpoints[0] = Point{0,0};
//     Rombpoints[1] = Point{2,0};
//     Rombpoints[2] = Point{2,2};
//     Rombpoints[3] = Point{0,2};

    
 
//     // act
//     Romb romb{Rombpoints};
//     bool res = validateArray(Rombpoints, romb.getPoints(), 4);
//     // assert
    
//     EXPECT_EQ(res, true);
// }

// TEST(RombNeighboursSidesAreParralelValueExeption, BasicAssertions) {
//     // arrange 
//     Point* RombPoints = new Point[4];
//     RombPoints[0] = Point{2,4};
//     RombPoints[1] = Point{4,8};
//     RombPoints[2] = Point{2,3};
//     RombPoints[3] = Point{6,3};

//     // assert
//     EXPECT_THROW(Romb romb{RombPoints};, std::invalid_argument);

// }

// TEST(RombSideZeroLengthValueExeption, BasicAssertions) {
//     // arrange 
//     Point* RombPoints = new Point[4];
//     RombPoints[0] = Point{2,5};
//     RombPoints[1] = Point{2,5};
//     RombPoints[2] = Point{2,3};
//     RombPoints[3] = Point{6,3};

//     // assert
//     EXPECT_THROW(Romb romb{RombPoints};, std::invalid_argument);

// }

// TEST(RombOppositeSidesArentParalelValueExeption, BasicAssertions) {
//     // arrange 
//     Point* RombPoints = new Point[4];
//     RombPoints[0] = Point{2,6};
//     RombPoints[1] = Point{13,4};
//     RombPoints[2] = Point{9,11};
//     RombPoints[3] = Point{37,2};

//     // assert
//     EXPECT_THROW(Romb romb{RombPoints};, std::invalid_argument);

// }

// TEST(RombCenter, BasicAssertions) {
//     // arrange 
//     Point* Rombpoints = new Point[4];
//     Rombpoints[0] = Point{0,0};
//     Rombpoints[1] = Point{2,0};
//     Rombpoints[2] = Point{2,2};
//     Rombpoints[3] = Point{0,2};
//     Romb romb{Rombpoints};
//     Point expectedCenter = Point{1,1};
//     // act
    
//     Point center = romb.center();
//     // assert
    
//     EXPECT_DOUBLE_EQ(center.getX(), expectedCenter.getX());
//     EXPECT_DOUBLE_EQ(center.getY(), expectedCenter.getY());
// }

// TEST(RombSquare, BasicAssertions) {
//     // arrange 
//     Point* Rombpoints = new Point[4];
//     Rombpoints[0] = Point{0,0};
//     Rombpoints[1] = Point{2,0};
//     Rombpoints[2] = Point{2,2};
//     Rombpoints[3] = Point{0,2};
//     double expectedSquare = 4;
//     // act
//     Romb romb{Rombpoints};
//     double square = (double) romb;
//     // assert
    
//    EXPECT_DOUBLE_EQ(square, expectedSquare);
// }

// TEST(PentagonPointConstructor, BasicAssertions) {
//     // arrange 
//     Point* PentagonPoints = new Point[5];
//     PentagonPoints[0] = Point{0,0};
//     PentagonPoints[1] = Point{2,0};
//     PentagonPoints[2] = Point{22,4};
//     PentagonPoints[3] = Point{3,12};
//     PentagonPoints[4] = Point{5,8};
 
//     // act
//     Pentagon pentagon{PentagonPoints};

//     // assert
//     bool res = validateArray(PentagonPoints, pentagon.getPoints(), 5);
//     EXPECT_EQ(res, true);
// }

// TEST(PentagonSideZeroLengthValueExeption, BasicAssertions) {
//     // arrange 
//     Point* PentagonPoints = new Point[5];
//     PentagonPoints[0] = Point{0,0};
//     PentagonPoints[1] = Point{2,2};
//     PentagonPoints[2] = Point{2,2};
//     PentagonPoints[3] = Point{3,12};
//     PentagonPoints[4] = Point{5,8};

//     // assert
//     EXPECT_THROW(Pentagon pentagon{PentagonPoints};, std::invalid_argument);

// }

// TEST(PentagonNeigboursSidesAreParelelValueExeption, BasicAssertions) {
//     // arrange 
//     Point* PentagonPoints = new Point[5];
//     PentagonPoints[0] = Point{1,1};
//     PentagonPoints[1] = Point{2,2};
//     PentagonPoints[2] = Point{3,3};
//     PentagonPoints[3] = Point{4,4};
//     PentagonPoints[4] = Point{5,8};

//     // assert
//     EXPECT_THROW(Pentagon pentagon{PentagonPoints};, std::invalid_argument);

// }

// TEST(PentagonCenter, BasicAssertions) {
//     // arrange 
//     Point* PentagonPoints = new Point[5];
//     PentagonPoints[0] = Point{0,0};
//     PentagonPoints[1] = Point{2,0};
//     PentagonPoints[2] = Point{22,4};
//     PentagonPoints[3] = Point{3,12};
//     PentagonPoints[4] = Point{5,8};
//     Pentagon pentagon{PentagonPoints};
//     Point expectedCenter = Point{6.4, 4.8};
//     // act
    
//     Point center = pentagon.center();
//     // assert
    
//     EXPECT_DOUBLE_EQ(center.getX(), expectedCenter.getX());
//     EXPECT_DOUBLE_EQ(center.getY(), expectedCenter.getY());
// }

// TEST(PentagonSquare, BasicAssertions) {
//     // arrange 
//     Point* PentagonPoints = new Point[5];
//     PentagonPoints[0] = Point{0,0};
//     PentagonPoints[1] = Point{2,0};
//     PentagonPoints[2] = Point{22,4};
//     PentagonPoints[3] = Point{3,12};
//     PentagonPoints[4] = Point{5,8};
//     Pentagon pentagon{PentagonPoints};
//     double expectedSquare = 112;
//     // act
    
//     double square = (double) pentagon;
//     // assert
    
//     EXPECT_DOUBLE_EQ(square, expectedSquare);
// }

// // TEST(FigureListPushBack, BasicAssertions) {
// //     // arrange 
// //     Point* TrapPoints = new Point[4];
// //     TrapPoints[0] = Point{0,0};
// //     TrapPoints[1] = Point{7,0};
// //     TrapPoints[2] = Point{2,3};
// //     TrapPoints[3] = Point{6,3};


// //     Point* Rombpoints = new Point[4];
// //     Rombpoints[0] = Point{0,0};
// //     Rombpoints[1] = Point{2,0};
// //     Rombpoints[2] = Point{2,2};
// //     Rombpoints[3] = Point{0,2};

// //     Point* PentagonPoints = new Point[5];
// //     PentagonPoints[0] = Point{0,0};
// //     PentagonPoints[1] = Point{2,0};
// //     PentagonPoints[2] = Point{22,4};
// //     PentagonPoints[3] = Point{3,12};
// //     PentagonPoints[4] = Point{5,8};

// //     std::vector<std::string> expectedFigures;

// //     expectedFigures.push_back("Pentagon");
// //     expectedFigures.push_back("Trap");
// //     expectedFigures.push_back("Romb");

// //     Figure* pentagon = Pentagon::create(PentagonPoints);

// //     FigureList list;
   
// //     // act
    
// //     list.push_back(pentagon);
// //     list.push_back(dynamic_cast<Figure*>(new Trap(TrapPoints)));
// //     list.push_back(dynamic_cast<Figure*>(new Romb(Rombpoints)));

// //     bool res = validateFiguresInArray(list,expectedFigures);
// //     // assert
    
// //    EXPECT_EQ(res, true);
// // }


// TEST(FigureListRemove, BasicAssertions) {
//     // arrange 
//     Point* TrapPoints = new Point[4];
//     TrapPoints[0] = Point{0,0};
//     TrapPoints[1] = Point{7,0};
//     TrapPoints[2] = Point{2,3};
//     TrapPoints[3] = Point{6,3};


//     Point* Rombpoints = new Point[4];
//     Rombpoints[0] = Point{0,0};
//     Rombpoints[1] = Point{2,0};
//     Rombpoints[2] = Point{2,2};
//     Rombpoints[3] = Point{0,2};

//     Point* PentagonPoints = new Point[5];
//     PentagonPoints[0] = Point{0,0};
//     PentagonPoints[1] = Point{2,0};
//     PentagonPoints[2] = Point{22,4};
//     PentagonPoints[3] = Point{3,12};
//     PentagonPoints[4] = Point{5,8};

//     std::vector<std::string> expectedFigures;

//     expectedFigures.push_back("Pentagon");
//     expectedFigures.push_back("Trap");
//     expectedFigures.push_back("Romb");

//     Figure* pentagon = Pentagon::create(PentagonPoints);

//     FigureList list;

//     list.push_back(pentagon);
//     list.push_back(dynamic_cast<Figure*>(new Trap(TrapPoints)));
//     list.push_back(dynamic_cast<Figure*>(new Romb(Rombpoints)));
   
//     // act
    
//     list.remove(1);
    

//     int res = list.getSize();
//     // assert
    
//    EXPECT_EQ(res, 2);
// }

// TEST(FigureListIndBelowZero, BasicAssertions) {
//     // arrange 
//     FigureList list;

//     // assert
//     EXPECT_THROW(list[-4];, std::invalid_argument);

// }

// TEST(FigureListIndBiggerThanSize, BasicAssertions) {
//     // arrange 
//     FigureList list;

//     // assert
//     EXPECT_THROW(list[2];, std::invalid_argument);

// }

