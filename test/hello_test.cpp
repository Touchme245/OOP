#include <gtest/gtest.h>
#include "Six.h"

TEST(DefaultConstructor, BasicAssertions) {
  // arrange 
  Six obj {};
  int expectedSize = 0;
  // act
  int size = obj.getSize();
  unsigned char* array = obj.getArray();

  // assert
  EXPECT_EQ(size, expectedSize);
  EXPECT_EQ(array, nullptr);
}

TEST(FillConstructor, BasicAssertions) {
  // arrange 
  int n = 5;
  char val = '0';
  Six obj(n, val);
  int expectedSize = 5;

  unsigned char expectedArray[] = "00000";

  // act
  int size = obj.getSize();
  unsigned char* array = obj.getArray();

  // assert
  EXPECT_EQ(size, expectedSize);
  for (int i =0; i < size; ++i){
    EXPECT_EQ(array[i], expectedArray[i]);
  }
  
}

TEST(FillConstructorValueExeption, BasicAssertions) {
  // arrange 
  int n = 5;
  char val = 'k';

  EXPECT_THROW(Six obj(n, val);, std::invalid_argument);

}

TEST(ListConstructor, BasicAssertions) {
  // arrange 
  Six obj {'5', '5', '5', '5'};
  unsigned char expectedArray[] = "5555";
  int expectedSize = 4;
  // act
  int size = obj.getSize();
  unsigned char* array = obj.getArray();

  // assert
  EXPECT_EQ(size, expectedSize);
  for (int i =0; i < size; ++i){
    EXPECT_EQ(array[i], expectedArray[i]);
  }
}

TEST(ListConstructorValueExeption, BasicAssertions) {
  // arrange 
  int n = 5;
  

  EXPECT_THROW(Six obj('k','k');, std::invalid_argument);

}

TEST(StringConstructor, BasicAssertions) {
  // arrange 
  Six obj {"5555"};
  unsigned char expectedArray[] = "5555";
  int expectedSize = 4;
  // act
  int size = obj.getSize();
  unsigned char* array = obj.getArray();

  // assert
  EXPECT_EQ(size, expectedSize);
  for (int i =0; i < size; ++i){
    EXPECT_EQ(array[i], expectedArray[i]);
  }
}

TEST(StringConstructorValueExeption, BasicAssertions) {
  // arrange 
  int n = 5;
  

  EXPECT_THROW(Six obj{"kj"};, std::invalid_argument);

}

TEST(CopyConstructor, BasicAssertions) {
  // arrange 
  Six parentObj {"5555"};
  Six obj {parentObj};
  unsigned char* expectedArray = parentObj.getArray();
  int expectedSize = 4;
  // act
  int size = obj.getSize();
  unsigned char* array = obj.getArray();

  // assert
  EXPECT_EQ(size, expectedSize);
  for (int i =0; i < size; ++i){
    EXPECT_EQ(array[i], expectedArray[i]);
  }
}

TEST(MoveConstructor, BasicAssertions) {
  // arrange 
  Six parentObj {'1', '1', '1', '1'};
  Six obj(std::move(parentObj));
  unsigned char expectedArray[] = "1111";
  int expectedSize = 4;
  // act
  int size = obj.getSize();
  unsigned char* array = obj.getArray();

  // assert
  EXPECT_EQ(size, expectedSize);
  for (int i =0; i < size; ++i){
    EXPECT_EQ(array[i], expectedArray[i]);
  }
}

TEST(addOperation1, BasicAssertions) {
  // arrange 
  Six first {"1111"};
  Six second {"1111"};
 
  unsigned char expectedArray[] = "2222";
  int expectedSize = 4;
  // act
   Six res{first.add(second)};
  int size = res.getSize();
  unsigned char* array = res.getArray();

  // assert
  EXPECT_EQ(size, expectedSize);
  for (int i =0; i < size; ++i){
    EXPECT_EQ(array[i], expectedArray[i]);
  }
}

TEST(addOperation2, BasicAssertions) {
  // arrange 
  Six first {"12345"};
  Six second {"12345"};
 
  unsigned char expectedArray[] = "43152";
  int expectedSize = 5;
  // act
   Six res{first.add(second)};
  int size = res.getSize();
  unsigned char* array = res.getArray();

  // assert
  EXPECT_EQ(size, expectedSize);
  for (int i =0; i < size; ++i){
    EXPECT_EQ(array[i], expectedArray[i]);
  }
}



TEST(RemoveOperation1, BasicAssertions) {
  // arrange 
  Six first {"12345"};
  Six second {"12345"};
 
  unsigned char expectedArray[] = "0";
  int expectedSize = 1;
  // act
   Six res{first.remove(second)};
  int size = res.getSize();
  unsigned char* array = res.getArray();
  std::cout << size << "\n";

  // assert
  EXPECT_EQ(size, expectedSize);
  for (int i =0; i < size; ++i){
    EXPECT_EQ(array[i], expectedArray[i]);
  }
}

TEST(RemoveOperation2, BasicAssertions) {
  // arrange 
  Six first {"12345"};
  Six second {"1234"};
 
  unsigned char expectedArray[] = "11111";
  int expectedSize = 5;
  // act
  Six res{first.remove(second)};
  int size = res.getSize();
  unsigned char* array = res.getArray();
  

  // assert
  EXPECT_EQ(size, expectedSize);
  for (int i =0; i < size; ++i){
    EXPECT_EQ(array[i], expectedArray[i]);
  }
}

TEST(RemoveOperationLogicExeption, BasicAssertions) {
  // arrange 
  int n = 5;
  Six first {"12345"};
  Six second {"1234"};
  

  EXPECT_THROW(second.remove(first);, std::logic_error);

}

TEST(Equals, BasicAssertions) {
  // arrange 
  Six first {"12345"};
  Six second {"12345"};
 
  // act
 bool res = first.equals(second);
  
  // assert
  EXPECT_EQ(res, 1);
  
}

// TEST(Equals2, BasicAssertions) {
//   // arrange 
//   Six first {"12345"};
//   Six second {"1235"};
 
//   // act
//  bool res = first.equals(second);
  

//   // assert
//   EXPECT_EQ(res, 0);
  
// }

TEST(OperatorGreter1, BasicAssertions) {
  // arrange 
  Six first {"12345"};
  Six second {"1235"};
 
  // act
 bool res = first.operator>(second);
  
  // assert
  EXPECT_EQ(res, 1);
  
}

TEST(OperatorGreter2, BasicAssertions) {
  // arrange 
  Six first {"12345"};
  Six second {"123555"};
 
  // act
 bool res = first.operator>(second);
  

  // assert
  EXPECT_EQ(res, 0);
  
}

TEST(OperatorLower, BasicAssertions) {
  // arrange 
  Six first {"12345"};
  Six second {"123555"};
 
  // act
 bool res = first.operator<(second);
  

  // assert
  EXPECT_EQ(res, 1);
  
}

TEST(OperatorLower2, BasicAssertions) {
  // arrange 
  Six first {"123434345"};
  Six second {"123555"};
 
  // act
 bool res = first.operator<(second);
  

  // assert
  EXPECT_EQ(res, 0);
  
}

