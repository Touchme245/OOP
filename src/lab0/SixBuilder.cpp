#include "SixBuilder.h"
#include "Six.h"


SixBuilder::SixBuilder()=default;

SixBuilder& SixBuilder::size(long long value){
    object._size = value;
    return *this;
}

SixBuilder& SixBuilder::data(unsigned char * value){
    object._array = value;
    return *this;
}

Six SixBuilder::build(){
    return object;
}

