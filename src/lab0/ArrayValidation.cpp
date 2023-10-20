#include "Point.h"
#include "ArrayValidation.h"
bool validateArray(const Point* points1,const Point* points2, const int size){
    for (int i = 0; i < size; ++i){
        if (points1[i] != points2[i]){
            return false;
        }
    }
    return true;

}