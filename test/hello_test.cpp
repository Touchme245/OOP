#include <gtest/gtest.h>
#include "calculate.h"
#include <string>

TEST(ExampleOfStandartUsageTest1, BasicAssertions) {
  // arrange 
  int leftBorder = 2;
  int rightBorder = 7;

  // act
  int res = calculate(leftBorder, rightBorder);

  // assert
  EXPECT_EQ(res, 11);
}

TEST(ExampleOfStandartUsageTest2, BasicAssertions) {
  // arrange 
  int leftBorder = 10;
  int rightBorder = 18;

  // act
  int res = calculate(leftBorder, rightBorder);

  // assert
  EXPECT_EQ(res, 22);
}

TEST(ExampleOfStandartUsagelTest3, BasicAssertions) {
  // arrange 
  int leftBorder = 3;
  int rightBorder = 9;

  // act
  int res = calculate(leftBorder, rightBorder);

  // assert
  EXPECT_EQ(res, 13);
}

TEST(sameValues, BasicAssertions) {
  // arrange 
  int leftBorder = 2;
  int rightBorder = 2;

  // act
  int res = calculate(leftBorder, rightBorder);

  // assert
  EXPECT_EQ(res, 1);
}

TEST(IncorrectBorders, BasicAssertions) {
  // arrange 
  int leftBorder = 10;
  int rightBorder = 2;

  // act
  int res = calculate(leftBorder, rightBorder);

  // assert
  EXPECT_EQ(res, 0);
}

