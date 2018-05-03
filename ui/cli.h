//
// Created by Marian on 3/28/2018.
//

#ifndef ASSIGNMENT05_06_CLI_H
#define ASSIGNMENT05_06_CLI_H


#include "../controller/controller.h"

class CLI {
public:
    CLI(Controller& controller): controller{controller}{};
    ~CLI();
    void start();
private:
    Controller controller;
    int getMinutes(string input);
    int getSeconds(string input);

    void showResults(vector<Tutorial> results, string name);
};


#endif //ASSIGNMENT05_06_CLI_H
