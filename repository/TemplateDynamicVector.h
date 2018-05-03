//
// Created by Marian on 4/2/2018.
//

#ifndef ASSIGNMENT05_06_TEMPLATEDYNAMICVECTOR_H
#define ASSIGNMENT05_06_TEMPLATEDYNAMICVECTOR_H

#include <cstdio>

template <typename T>
class TemplateDynamicVector {
private:
    int size;
    int capacity;
    T** elems;
    bool toDestroy;
    void resize(double factor);
public:
    TemplateDynamicVector(int capacity);
    TemplateDynamicVector(int capacity, bool toDestroy);
    ~TemplateDynamicVector();
    T& operator[](int pos);

    void operator-(T* elemToRemove);

    //add an element to the vector
    void add(T* e);

    void remove(T* e);
    int getSize() const;
    void decSize();

    bool exists(T* elem);
};

template<typename T>
TemplateDynamicVector<T>::TemplateDynamicVector(int capacity) {
    /**
     * Create a vector with the given capacity
     * @param capacity: the initial capacity of the vector
     */
    this->toDestroy = true;
    this->size = 0;
    this->capacity = capacity;
    this->elems = new T*[this->capacity];
}

template<typename T>
TemplateDynamicVector<T>::~TemplateDynamicVector() {
    /**
     * Clean up the used pointers
     */
    for(int i=0; i<this->size; i++) {
        if(elems[i] != NULL and toDestroy) {
            delete elems[i];
            elems[i] = NULL;
        }
    }
    delete[] elems;
    elems = NULL;
}

template<typename T>
T &TemplateDynamicVector<T>::operator[](int pos) {
    /**
     *
     */
    return *this->elems[pos];
}

template<typename T>
void TemplateDynamicVector<T>::add(T *e) {
    /**
     * Add the element e to the vector if it doesn't exist already
     */
    for(int i=0; i<size; i++) {
        if(elems[i]->getTitle() == e->getTitle())
            return;
    }
    if(this->size == this->capacity) {
        this->resize(2);
    }
    this->elems[this->size] = e;
    this->size++;
}

template<typename T>
void TemplateDynamicVector<T>::remove(T *e) {
    /**
     * Remove the elem. e from the vector if it exists
     */
    for(int i=0; i<this->size; i++) {
        if(this->elems[i] == e) {
            for(int j=i; j<this->size-1; j++) {
                if(toDestroy and j==i) {
                    //will only delete when it is an instance of the main repo
                    delete elems[j];
                }
                this->elems[j] = this->elems[j+1];
            }
            this->size--;
            break;
        }
    }
}

template<typename T>
int TemplateDynamicVector<T>::getSize() const {
    /**
     *
     */
    return this->size;
}

template<typename T>
bool TemplateDynamicVector<T>::exists(T *elem) {
    for(int i=0; i<this->size; i++) {
        if(elem == this->elems[i]) {
            return true;
        }
    }
    return false;
}

template<typename T>
void TemplateDynamicVector<T>::resize(double factor) {
    /**
     * Resize the vector by the given factor
     */
    this->capacity*= factor;

    T** els = new T*[this->capacity];
    for(int i=0; i<this->size; i++) {
        els[i] = this->elems[i];
    }
    delete[] this->elems;
    this->elems = els;
}

template<typename T>
void TemplateDynamicVector<T>::operator-(T *elemToRemove) {
    if(this->exists(elemToRemove)) {
        this->remove(elemToRemove);
    }
}

template<typename T>
void TemplateDynamicVector<T>::decSize() {
    this->size--;
}

template<typename T>
TemplateDynamicVector<T>::TemplateDynamicVector(int capacity, bool toDestroy) {
    /**
     * Constructor used for instantiating the watchList repo.
     * Setting the toDestroy param. to false will tell the vector not to destroy the individual pointers stored
     *
     */
    this->toDestroy = toDestroy;
    this->size = 0;
    this->capacity = capacity;
    this->elems = new T*[this->capacity];
}


#endif //ASSIGNMENT05_06_TEMPLATEDYNAMICVECTOR_H