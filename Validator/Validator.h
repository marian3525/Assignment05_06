//
// Created by Marian on 4/1/2018.
//

#ifndef ASSIGNMENT05_06_VALIDATOR_H
#define ASSIGNMENT05_06_VALIDATOR_H
using namespace std;

class Validator {
public:
    static void validateAdd(string title, string presenter, int duration, int likes, string link);
    static void validateRemove(string title);
    static int validateUpdate(string title, string presenter, int duration, int likes, string link);
    static void validateAddToWatchlist(string title);
};


#endif //ASSIGNMENT05_06_VALIDATOR_H
