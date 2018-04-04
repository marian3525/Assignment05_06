//
// Created by Marian on 3/28/2018.
//

#ifndef ASSIGNMENT05_06_CONTROLLER_H
#define ASSIGNMENT05_06_CONTROLLER_H


#include "../repository/repository.h"

class Controller {
public:
    Controller(Repository* repo);
    ~Controller();
    int addTutorial(string title, string presenter, int duration, int likes, string link);
    int removeTutorial(string title);
    int updateTutorial(string title, string presenter, int duration, int likes, string link);
    string* getAllPrintable(int& n);
    Tutorial** filterByPresenter(string presenter, int& numberOfResults);
    int addToWatchList(string name);
    Tutorial** getWatchList(int &n);
    void likeTutorial(string title);
    void deleteFromWatchlist(string name);
private:
    Repository* repo;
    Repository* watchList;
    void populateRepo();
};


#endif //ASSIGNMENT05_06_CONTROLLER_H
