//
// Created by Marian on 5/3/2018.
//

#ifndef ASSIGNMENT05_06_CSVWRITER_H
#define ASSIGNMENT05_06_CSVWRITER_H


#include "Writer.h"
#include "../repository/repository.h"

class CSVWriter: Writer {
public:
    void write(Repository& repo) override;
    CSVWriter();
private:
};


#endif //ASSIGNMENT05_06_CSVWRITER_H
