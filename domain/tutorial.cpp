#include <cstring>
#include <cstdio>
#include "tutorial.h"

Tutorial::Tutorial(string title, string presenter, int duration, int likes, string link) {
    this->title= title;
    this->presenter= presenter;
    this->duration = duration;
    this->likes = likes;
    this->link= link;
}

Tutorial::Tutorial(const Tutorial &t) {
    //allocating space for the char strings
    this->title = new char[50];
    this->presenter = new char[50];
    this->link = new char[50];

    this->title=t.title;
    this->presenter=t.presenter;
    this->duration = t.duration;
    this->likes = t.likes;
    this->link=t.link;
}

Tutorial::~Tutorial() {
    //destructors for the strings are called once they go out of scope
}

bool Tutorial::operator==(const Tutorial &tutorial) {
    if(this->title==tutorial.title and this->presenter==tutorial.presenter
            and this->link==tutorial.link and this->likes == tutorial.likes
            and this->duration == tutorial.duration) {
        return true;
    }
    return false;
}

string Tutorial::getLink() {
    return this->link;
}

int Tutorial::getLikes() {
    return this->likes;
}

int Tutorial::getDuration() {
    return this->duration;
}

string Tutorial::getPresenter() {
    return this->presenter;
}

string Tutorial::getTitle() {
    return this->title;
}

void Tutorial::setPresenter(string presenter) {
    this->presenter= presenter;
}

void Tutorial::setDuration(int duration) {
    this->duration = duration;
}

void Tutorial::setLikes(int likes) {
    this->likes = likes;
}

void Tutorial::setLink(string link) {
    this->link=link;
}

string Tutorial::toString() {
    string output = "Tutorial name: ";
    output+=this->title;
    output+="\n";

    output += "Presenter: ";
    output+=this->presenter;
    output+="\n";

    output+= "Duration: ";
    output+= (to_string(this->duration/60) + "m");
    output+= (to_string(this->duration%60) + "s");
    output+= "\n";

    output+= "Likes: ";
    output+= to_string(this->likes);
    output+= "\n";

    output+= "Link: ";
    output+= this->link;
    output+= "\n";

    return output;
}

void Tutorial::incLikes() {
    this->likes++;

}
