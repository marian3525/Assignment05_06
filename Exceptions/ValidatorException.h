//
// Created by Marian on 4/26/2018.
//

#include <exception>
#include <string>
#ifndef ASSIGNMENT05_06_VALIDATOREXCEPTION_H
#define ASSIGNMENT05_06_VALIDATOREXCEPTION_H


using namespace std;
class ValidatorException: exception {
private:
    string msg;
public:
    explicit ValidatorException(string errorMsg);
    const string getMessage() const;
};


#endif //ASSIGNMENT05_06_VALIDATOREXCEPTION_H
