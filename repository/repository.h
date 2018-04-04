//
// Created by Marian on 3/28/2018.
//

#ifndef ASSIGNMENT05_06_REPOSITORY_H
#define ASSIGNMENT05_06_REPOSITORY_H


#include "../domain/tutorial.h"
#include "DynamicVector.h"
#include "TemplateDynamicVector.h"

class Repository {
private:
    TemplateDynamicVector<Tutorial>* elems;
public:

    Repository();
    Repository(bool toDestroy);
    ~Repository();
    void add(Tutorial* tutorial);
    void remove(string nameToRemove);

    //the name cannot be changed
    void update(string nameToUpdate, string presenter, int duration, int likes, string link);
    bool existsByTitle(string title);
    Tutorial* getByTitle(string title);
    Tutorial** getAll();
    int getSize();
    void decSize();
    Tutorial& operator[](int pos);

};


#endif //ASSIGNMENT05_06_REPOSITORY_H
