//
// Created by Marian on 4/2/2018.
//

#ifndef ASSIGNMENT05_06_TEMPLATEDYNAMICVECTOR_H
#define ASSIGNMENT05_06_TEMPLATEDYNAMICVECTOR_H

template <typename T>
class TemplateDynamicVector {
private:
    int size;
    int capacity;
    T** elems;
    void resize(double factor);
public:
    TemplateDynamicVector(int capacity);
    ~TemplateDynamicVector();
    T& operator[](int pos);

    void operator-(T* elemToRemove);

    //add an element to the vector
    void add(T* e);

    void remove(T* e);
    int getSize() const;

    bool exists(T* elem);
};

template<typename T>
TemplateDynamicVector<T>::TemplateDynamicVector(int capacity) {
    this->size = 0;
    this->capacity = capacity;
    this->elems = new T*[this->capacity];
}

template<typename T>
TemplateDynamicVector<T>::~TemplateDynamicVector() {
    for(int i=0; i<this->size; i++) {
        if(elems[i] != nullptr) {
            delete elems[i];
            elems[i] = nullptr;
        }
    }
    delete[] elems;
    elems = nullptr;
}

template<typename T>
T &TemplateDynamicVector<T>::operator[](int pos) {
    return *this->elems[pos];
}

template<typename T>
void TemplateDynamicVector<T>::add(T *e) {
    if(this->size == this->capacity) {
        this->resize(2);
    }
    this->elems[this->size] = e;
    this->size++;
}

template<typename T>
void TemplateDynamicVector<T>::remove(T *e) {
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

template<typename T>
int TemplateDynamicVector<T>::getSize() const {
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


#endif //ASSIGNMENT05_06_TEMPLATEDYNAMICVECTOR_H
