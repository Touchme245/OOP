#pragma once
#include "ValidationHandler.h"

class TrapValidationHandler: public VaLidationHandler{
    public:
        void validate(const Figure& figure1) const override;
        virtual bool isAllowed(const Figure& fugure) const override;
};

