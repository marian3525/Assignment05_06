//
// Created by Marian on 3/28/2018.
//

#ifndef ASSIGNMENT05_06_DYNAMICVECTOR_H
#define ASSIGNMENT05_06_DYNAMICVECTOR_H


#include "../domain/tutorial.h"

typedef Tutorial TElem;

class DynamicVector{
private:
    TElem **elems;
    int size;
    int capacity;

public:
    //default constructor
    DynamicVector(int capacity=10);

    //copy constructor
    DynamicVector(const DynamicVector& v);
    ~DynamicVector();

    //assignment operator for a DynamicVector
    DynamicVector& operator=(const DynamicVector& v);

    TElem& operator[](int pos);

    void operator-(TElem* elemToRemove);

    //add an element to the vector
    void add(TElem* e);

    void remove(TElem* e);
    int getSize() const;

    bool exists(TElem* elem);

private:
    void resize(double factor = 2);
};


#endif //ASSIGNMENT05_06_DYNAMICVECTOR_H
