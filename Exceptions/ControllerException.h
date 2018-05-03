//
// Created by Marian on 4/28/2018.
//
#include <string>
using namespace std;
#ifndef ASSIGNMENT05_06_CONTROLLEREXCEPTION_H
#define ASSIGNMENT05_06_CONTROLLEREXCEPTION_H


class ControllerException {
private:
    string message;
public:
    explicit ControllerException(string msg): message{msg}{};
    const string getMessage() const;
};


#endif //ASSIGNMENT05_06_CONTROLLEREXCEPTION_H
