//
// Created by Marian on 4/26/2018.
//
#include <string>
#include <exception>
using namespace std;
#ifndef ASSIGNMENT05_06_REPOSITORYEXCEPTION_H
#define ASSIGNMENT05_06_REPOSITORYEXCEPTION_H


class RepositoryException: exception {
public:
    explicit RepositoryException(string errorMsg): msg{errorMsg}{};
    const string getMessage() const;
private:
    string msg;
};


#endif //ASSIGNMENT05_06_REPOSITORYEXCEPTION_H
