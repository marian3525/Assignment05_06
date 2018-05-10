//
// Created by Marian on 5/3/2018.
//

#ifndef ASSIGNMENT05_06_WRITER_H
#define ASSIGNMENT05_06_WRITER_H


#include "../repository/repository.h"

class Writer {
public:
    virtual void write(Repository& repo) = 0;
};


#endif //ASSIGNMENT05_06_WRITER_H
