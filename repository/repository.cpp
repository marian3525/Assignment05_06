#include <cstring>
#include "DynamicVector.h"
#include "repository.h"
#include "TemplateDynamicVector.h"

Repository::Repository() {
    this->elems = new TemplateDynamicVector<Tutorial>(10);
}

void Repository::add(Tutorial* elem) {
    this->elems->add(elem);
}

void Repository::remove(string nameToDelete) {
    for(int i=0; i<this->elems->getSize(); i++) {
        if((*elems)[i].getTitle()==nameToDelete) {
            this->elems->remove(&(*elems)[i]);
        }
    }
}


void Repository::update(string nameToUpdate, string presenter, int duration, int likes, string link) {
    for(int i=0; i<this->elems->getSize(); i++) {
        if((*elems)[i].getTitle()==nameToUpdate) {
            (*elems)[i].setPresenter(presenter);
            (*elems)[i].setDuration(duration);
            (*elems)[i].setLikes(likes);
            (*elems)[i].setLink(link);
        }
    }
}

int Repository::getSize() {
    return this->elems->getSize();
}

void Repository::decSize() {
    this->elems->decSize();
}

TElem& Repository::operator[](int pos) {
    return this->elems->operator[](pos);
}

Tutorial** Repository::getAll() {
    Tutorial** all = new Tutorial*[this->getSize()];

    for(int i=0; i<this->getSize(); i++) {
        all[i] = &(*elems)[i];
    }
    return all;
}

bool Repository::existsByTitle(string title) {
    for(int i=0; i<this->getSize(); i++) {
        if((*elems)[i].getTitle() == title) {
            return true;
        }
    }
    return false;
}

Repository::~Repository() {
    delete elems;
}

Tutorial *Repository::getByTitle(string title) {
    if(this->existsByTitle(title)) {
        for(int i=0; i<this->getSize(); i++) {
            if((*elems)[i].getTitle() == title) {
                return &(*elems)[i];
            }
        }
    }
}

Repository::Repository(bool toDestroy) {
    this->elems = new TemplateDynamicVector<Tutorial>(10, toDestroy);
}
