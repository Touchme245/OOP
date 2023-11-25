// #include <gtest/gtest.h>
// #include "./../src/lab0/Aloctr.cpp"
// #include "./../src/lab0/Vector2.cpp"
// #include <map>


// TEST(VectorDefaultConstructor, BasicAssertions) {
//     // arrange 
//     int expectedSize = 0;
//     // act
//    MyVector::Vector<int, mai::allocator<int, 10>> vect;
    
//     // assert
//    EXPECT_EQ(vect.getSize(), 0);
// }


// TEST(PushBack, BasicAssertions) {
//     // arrange 
//     MyVector::Vector<int, mai::allocator<int, 10>> vect;
//     int expectedSize = 1;
//     // act
//     vect.push_back(2);
    
//     // assert
//     EXPECT_EQ(vect.getSize(), 1);
//     EXPECT_EQ(vect[0], 2);
// }

// TEST(PushBackOutOfBoundsExeption, BasicAssertions) {
//     // arrange 
//     MyVector::Vector<int, mai::allocator<int, 10>> vect;
//     int expectedSize = 1;
//     // act
//     vect.push_back(2);
    
//     // assert
//    EXPECT_THROW(vect[12];, std::out_of_range);
// }


// TEST(Iterators, BasicAssertions) {
//     // arrange 
//     int expectedSize = 0;
//     MyVector::Vector<int, mai::allocator<int, 10>> vect;
//     for (int i = 0; i < 10; ++i){
//         vect.push_back(i);
//     }
//     int res = 1;
//     int i = 0;
//     // act
//     for (auto e : vect){
//         if (e != i){
//             res = 0;
//             break;
//         }
//         i++;
//     }
    
//     // assert
//     EXPECT_EQ(res, 1);
// }