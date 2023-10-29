#include "ValidationCompositor.h"
#include <vector>



template<class T> void ValidationCompositor<T>::validate(Figure<T>& figure) const{
    for (std::shared_ptr<VaLidationHandler<T>> validator : validations){
       // VaLidationHandler* validator = validations[i];
       
        if (validator.get()->isAllowed(figure)){
            validator.get()->validate(figure);
            return;
        }
    }
}

template<class T> ValidationCompositor<T>::ValidationCompositor(){
    
    validations.push_back(dynamic_cast< std::shared_ptr<VaLidationHandler<T>> >( new TrapValidationHandler()));
    validations.push_back(dynamic_cast<std::shared_ptr<VaLidationHandler<T>> >(new RombValidationHandler()));
    validations.push_back(dynamic_cast<std::shared_ptr<VaLidationHandler<T>> >(new PentagonValidationHandler()));
    
}

// ValidationCompositor::~ValidationCompositor(){
//     for (int i = 0; i < validations.size(); ++i){
//         delete validations[i];
        
//     }
// }