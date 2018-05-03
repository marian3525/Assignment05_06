//
// Created by Marian on 4/1/2018.
//

#include <cstring>
#include <string>
#include "Validator.h"
#include "../Exceptions/ValidatorException.h"

using namespace std;

void Validator::validateAdd(string title, string presenter, int duration, int likes, string link) {
    string errors="";

    if(title.size()==0) {
        errors.append("Title is empty!\n");
    }
    if(presenter.size() == 0) {
        errors.append("Presenter name empty!\n");
    }
    if(duration <= 0) {
        errors.append("Duration must be greater than 0!\n");
    }
    if(likes < 0) {
        errors.append("Likes must be better than 0!\n");
    }
    if(link.size() == 0) {
        errors.append("The link cannot be empty!\n");
    }
    if(errors.size()>0) {
        throw ValidatorException{errors};
    }
}

void Validator::validateRemove(string title) {
    if(title.size() == 0) {
        throw ValidatorException("Cannot remove, invalid title");
    }
}

void Validator::validateAddToWatchlist(string title) {
    if(title.size()==0)
        throw ValidatorException("Cannot add to watchlist, title is empty");
}
