//
// Created by Marian on 4/26/2018.
//

#include "ValidatorException.h"

const string ValidatorException::getMessage() const {
    return this->msg;
}

ValidatorException::ValidatorException(string errorMsg) {
    this->msg = errorMsg;
}