//
// Created by Marian on 4/1/2018.
//

#include <cstring>
#include <string>
#include "Validator.h"
using namespace std;

int Validator::validateAdd(string title, string presenter, int duration, int likes, string link) {
    if(title.size()==0) {
        return 1;
    }
    if(presenter.size() == 0) {
        return 2;
    }
    if(duration <= 0) {
        return 3;
    }
    if(likes < 0) {
        return 4;
    }
    if(link.size() == 0) {
        return 5;
    }
    return 0;
}

int Validator::validateRemove(string title) {
    if(title.size() != 0) {
        return 0;
    }
    return 1;
}

int Validator::validateAddToWatchlist(string title) {
    if(title.size()==0)
        return 1;
    return 0;
}
