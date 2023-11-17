#include <gtest/gtest.h>
#include "./../src/lab0/Aloctr.cpp"
#include <map>
TEST(UsingAllocatorWidthMap, BasicAssertions) {
    // arrange 
     int n = 5;
    std::map<int, int, std::less<int>, mai::allocator<std::pair<const int, int>, 10>> map;

   
    int i = 1;
    // act
    for (int i = 1; i < n; ++i){
        map.insert(std::pair<int, int>(i, i+1));
    }
    
    // assert
    int res = 1;
    for (auto p : map){
        if (p.first != i || p.second != (i+1)){
            res = 0;
            break;
        }

        i++;
    }
    EXPECT_EQ(res, 1);
}