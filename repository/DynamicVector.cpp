#include <cstdlib>
#include "DynamicVector.h"

DynamicVector::DynamicVector(int capacity) {
    this->size = 0;
    this->capacity = capacity;
    this->elems = new TElem*[this->capacity];
}

DynamicVector::DynamicVector(const DynamicVector &v) {
    this->size = v.size;
    this->capacity = v.capacity;
    this->elems = new TElem*[this->capacity];
    for(int i=0; i<this->size; i++) {
        this->elems[i] = v.elems[i];
    }
}

DynamicVector::~DynamicVector() {
    for(int i=0; i<this->size; i++) {
        if(elems[i] != NULL) {
            delete elems[i];
            elems[i] = NULL;
        }
    }
    delete[] elems;
    elems = NULL;
}

DynamicVector& DynamicVector::operator=(const DynamicVector &v) {
    if(this == &v) {
        return *this;
    }

    this->size = v.size;
    this->capacity = v.capacity;

    delete[] this->elems;
    this->elems = new TElem*[this->capacity];
    for(int i=0; i<this->size; i++) {
        this->elems[i] = v.elems[i];
    }
    return *this;
}

TElem& DynamicVector::operator[](int pos) {
    return *(this->elems[pos]);
}

void DynamicVector::add(TElem* elem) {
    if(this->size == this->capacity) {
        this->resize(2);
    }
    this->elems[this->size] = elem;
    this->size++;
}

void DynamicVector::resize(double factor) {
    this->capacity*= factor;

    TElem** els = (TElem**) malloc(this->capacity * sizeof(TElem*));
    for(int i=0; i<this->size; i++) {
        els[i] = this->elems[i];
    }
    delete[] this->elems;
    this->elems = els;
}

int DynamicVector::getSize() const {
    return this->size;
}

void DynamicVector::operator-(TElem *elemToRemove) {
    if(this->exists(elemToRemove)) {
        this->remove(elemToRemove);
    }
}

bool DynamicVector::exists(TElem* elem) {
    for(int i=0; i<this->size; i++) {
        if(elem == this->elems[i]) {
            return true;
        }
    }
    return false;
}

void DynamicVector::remove(TElem* e) {
    for(int i=0; i<this->size; i++) {
        if(this->elems[i] == e) {
            for(int j=i; j<this->size-1; j++) {
                this->elems[j] = this->elems[j+1];
            }
            this->size--;
            break;
        }
    }

}
