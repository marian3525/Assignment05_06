//
// Created by Marian on 3/28/2018.
//

#ifndef ASSIGNMENT05_06_REPOSITORY_H
#define ASSIGNMENT05_06_REPOSITORY_H


#include <vector>
#include "../domain/tutorial.h"
#include "DynamicVector.h"
#include "TemplateDynamicVector.h"

class Repository {
private:
    vector<Tutorial> elems;
    bool toDestroy = true;
public:
    explicit Repository(bool toDestroy);
    ~Repository();
    void add(Tutorial tutorial);
    void remove(string nameToRemove);

    //the name cannot be changed
    void update(string nameToUpdate, string presenter, int duration, int likes, string link);
    bool existsByTitle(string title);
    Tutorial& getByTitle(string title);
    vector<Tutorial> getAll();
    unsigned long getSize();
    void decSize();
    Tutorial& operator[](int pos);
    void sync();

};


#endif //ASSIGNMENT05_06_REPOSITORY_H
