//
// Created by Marian on 5/3/2018.
//

#ifndef ASSIGNMENT05_06_HTMLWRITER_H
#define ASSIGNMENT05_06_HTMLWRITER_H


#include "Writer.h"
#include "../repository/repository.h"

class HTMLWriter: Writer {
public:
    void write(Repository& repo) override;
    HTMLWriter();
private:
    Repository repo{true};
};


#endif //ASSIGNMENT05_06_HTMLWRITER_H
