#include "controller.h"
#include "../Validator/Validator.h"

Controller::Controller(Repository *repo) {
    this->repo = repo;
    this->watchList = new Repository(false);
    this->populateRepo();
}

void Controller::populateRepo() {
    Tutorial* tutorial;
    tutorial = new Tutorial(string("OOP"), string("Iuliana Bocicor"), 7000, 110, string("link1"));
    this->repo->add(tutorial);
    tutorial = new Tutorial(string("DSA"), string("Marian Zsuzsanna"), 7005, 129, string("link2"));
    this->repo->add(tutorial);
    tutorial = new Tutorial(string("GA"), string("Lupsa Radu-Lucian"), 6822, 98, string("link3"));
    this->repo->add(tutorial);
    tutorial = new Tutorial(string("OS"), string("Rares"), 6411, 77, string("link4"));
    this->repo->add(tutorial);
    tutorial = new Tutorial(string("SysDyn"), string("Buica A."), 7212, 132, string("link5"));
    this->repo->add(tutorial);
    tutorial = new Tutorial(string("Geometry"), string("Name"), 5983, 70, string("link6"));
    this->repo->add(tutorial);

}

string* Controller::getAllPrintable(int& n) {
    /**
     * Return a list of strings containing the printable version of each existing tutorial
     * @param n: number of elements found
     */
    string* output = new string[this->repo->getSize()];

    Tutorial** all =  repo->getAll();
    n = repo->getSize();

    for(int i=0; i<n; i++) {
        output[i] = string();
        output[i] = all[i]->toString();
    }
    delete[] all;
    return output;
}

int Controller::addTutorial(string title, string presenter, int duration, int likes, string link) {
    /**
     * @param title: title of the tutorial
     * @param presenter: the name of the presenter
     * @param duration; duration in seconds
     * @param likes: the numberof likes for the tutorial
     * @link: the link to the tutorial
     * @return 1 if validation failed and the elem. was not added, 0 otherwise
     */
    if(Validator::validateAdd(title, presenter, duration, likes, link)!=0) {
        return 1;
    }
    else {
        //passed validator, values must be valid
        Tutorial* tutorial = new Tutorial(title, presenter, duration, likes, link);
        this->repo->add(tutorial);
    }
    return 0;
}



Controller::~Controller() {
    delete watchList;
}

int Controller::removeTutorial(string title) {
    /**
     * @param title: The title of the tutorial to be removed
     * @return 1 if validation failed and the elem. was not removed, 0 otherwise
     */
    if(Validator::validateRemove(title) != 0) {
        return 1;
    }
    else {
        this->repo->remove(title);
        return 0;
    }
}

int Controller::updateTutorial(string title, string presenter, int duration, int likes, string link) {
    /**
     *  @param: the title of the tutorial to be updated
     *  @param: presenter: new name of the presenter
     *  @param: duration: new duration
     *  @param: likes: new number of likes
     *  @param: link: new link to the tutorial
     */
     if(Validator::validateAdd(title, presenter, duration, likes, link) != 0) {
         return 1;
     }
     else {
         if(this->repo->existsByTitle(title) == true) {
             this->repo->update(title, presenter, duration, likes, link);
         }
         else {
             return 2;
         }
         return 0;
     }
}

Tutorial** Controller::filterByPresenter(string presenter, int& numberOfResults) {
    /**
     * @param: presenter: the name of the presenter to filter by
     * @param: numberOfResults: a counter to return the number of elements found
     */
    Tutorial** results = new Tutorial*[repo->getSize()];
    Tutorial** all = this->repo->getAll();
    numberOfResults = 0;

    if(presenter == string("")) {
        numberOfResults = repo->getSize();
        return all;
    }

    for(int i=0; i<repo->getSize(); i++) {
        if(all[i]->getPresenter() == presenter) {
            results[numberOfResults++] = all[i];
        }
    }
    delete[] all;
    return results;
}

int Controller::addToWatchList(string name) {
    /**
     * @param name: name of the tutorial to  be added
     */
     if(Validator::validateAddToWatchlist(name)==0) {
         //check if it already was added
         if(!this->watchList->existsByTitle(name)) {
             this->watchList->add(repo->getByTitle(name));
             return 0;
         }
         else {
             return 1;
         }

     }
}

Tutorial** Controller::getWatchList(int &n) {
    n = this->watchList->getSize();
    Tutorial** result = new Tutorial*[n];

    for(int i=0; i<n; i++) {
        result[i] = &(*this->watchList)[i];
    }
    return result;
}

void Controller::deleteFromWatchlist(string name) {
    for(int i=0; i<this->watchList->getSize(); i++) {
        if (name == (*watchList)[i].getTitle()) {
            for (int j = i; j < watchList->getSize(); j++) {
                watchList->remove(name);
            }
            return;
        }
    }
}

void Controller::likeTutorial(string title) {
    for(int i=0; i<this->repo->getSize(); i++) {
        if((*repo)[i].getTitle() == title) {
            (*repo)[i].incLikes();
        }
    }
}




