#include <cstring>
#include "DynamicVector.h"
#include "repository.h"
#include "TemplateDynamicVector.h"
#include "../Exceptions/RepositoryException.h"
#include <algorithm>
#include <vector>
#include <fstream>

void Repository::add(Tutorial elem) {
    /**
     * Add the elem to the repo if it doesn't exist already
     */
    if (existsByTitle(elem.getTitle())) {
        throw RepositoryException{"Item already added\n"};
    } else {
        elems.push_back(elem);
    }
}

void Repository::remove(string nameToDelete) {
    /**
     * Remove the tutorial with the given name if it exists
     */
    auto it = find_if(elems.begin(), elems.end(), [nameToDelete](Tutorial &t) { return t.getTitle() == nameToDelete; });
    if (it != elems.end()) {
        elems.erase(it);
    } else {
        throw RepositoryException{"Tutorial does not exist!\n"};
    }
}


void Repository::update(string nameToUpdate, string presenter, int duration, int likes, string link) {
    /**
     * Update the tutorial with title <nameToUpdate> using the new attributes
     */
    auto it = find_if(elems.begin(), elems.end(), [nameToUpdate](Tutorial &t) { return t.getTitle() == nameToUpdate; });
    auto index = it - elems.begin();

    if (it != elems.end()) {
        elems[index].setPresenter(presenter);
        elems[index].setDuration(duration);
        elems[index].setLikes(likes);
        elems[index].setLink(link);
    } else {
        throw RepositoryException{"Cannot update, tutorial doesn't exist\n"};
    }
}

unsigned long Repository::getSize() {
    return elems.size();
}

Tutorial& Repository::operator[](int pos) {
    return elems[pos];
}

vector<Tutorial> Repository::getAll() {
    /**
     * Return a list of pointers to all the Tutorials currently in the repo
     */
    vector<Tutorial> aux;
    for_each(elems.begin(), elems.end(), [&aux](const Tutorial& t) {aux.push_back(t);});
    return aux;
}

bool Repository::existsByTitle(string title) {
    /**
     * Check if the tutorial with the given title is in the repo
     * @returns true: if tutorial is in the repo, false otherwise
     */
    auto it = find_if(elems.begin(), elems.end(), [title](Tutorial& t){return t.getTitle() == title;});
    return it != elems.end();
}

Repository::~Repository() {
    //if(toDestroy)
        //for_each(elems.begin(), elems.end(), [](Tutorial& t){delete &t;});
}

Tutorial& Repository::getByTitle(string title) {
    /**
     * Return the tutorial with the given title if it exists
     * null otherwise
     */
    auto it = find_if(elems.begin(), elems.end(), [title](Tutorial& t){return t.getTitle() == title;});
    if(it!=elems.end()) {
        auto index = it - elems.begin();
        return elems[index];
    }
}

Repository::Repository(bool toDestroy) {
    /**
     * Constructor to be used for the watchList, with the parameter set to false
     * When destroying this instance do not delete the individual elems. in the DynVector
     */
    this->toDestroy = toDestroy;
}

void Repository::sync() {
    vector<Tutorial> all = this->getAll();
    ofstream ofstream1("data.csv");

    for_each(all.begin(), all.end(), [&ofstream1](Tutorial& t){ofstream1<<t;});

    ofstream1<<";";
    ofstream1.close();
}