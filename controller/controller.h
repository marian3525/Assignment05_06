//
// Created by Marian on 3/28/2018.
//

#ifndef ASSIGNMENT05_06_CONTROLLER_H
#define ASSIGNMENT05_06_CONTROLLER_H


#include <fstream>
#include "../repository/repository.h"
#include "../Writers/Writer.h"

class Controller {
public:
    Controller();
    ~Controller();
    void addTutorial(string title, string presenter, int duration, int likes, string link);
    void removeTutorial(string title);
    void updateTutorial(string title, string presenter, int duration, int likes, string link);
    vector<string> getAllPrintable();
    vector<Tutorial> filterByPresenter(string presenter);
    void addToWatchList(string name);
    vector<Tutorial> getWatchList();
    void likeTutorial(string title);
    void deleteFromWatchlist(string name);
    string dumpHTMLString();
    string dumpCSVString();
    void sync();
    void setMode(Writer* writer);
    void write();
private:
    Repository repo = Repository{true};
    Repository watchList = Repository{true};
    void populateRepo();
    void populateRepoFromFile();
    Writer* writer;
};


#endif //ASSIGNMENT05_06_CONTROLLER_H
