#include <cstring>
#include <cstdio>
#include <ostream>
#include "tutorial.h"

Tutorial::Tutorial(string title, string presenter, int duration, int likes, string link) {
    /**
     * Create a tutorial with the given attributes
     */
    this->title= title;
    this->presenter= presenter;
    this->duration = duration;
    this->likes = likes;
    this->link= link;
}

Tutorial::Tutorial(const Tutorial &t) {
    /**
     * copy constructor
     */
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
    return this->title == tutorial.title and this->presenter == tutorial.presenter
           and this->link==tutorial.link and this->likes == tutorial.likes
           and this->duration==tutorial.duration;
}

string Tutorial::getLink()const {
    return this->link;
}

int Tutorial::getLikes()const {
    return this->likes;
}

int Tutorial::getDuration()const {
    return this->duration;
}

string Tutorial::getPresenter()const {
    return this->presenter;
}

string Tutorial::getTitle()const {
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

const string Tutorial::toString() const {
    /**
     * Return a string containing the attributes of this instance formatted and ready to print
     */
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
    /**
     *
     */
    this->likes++;

}

Tutorial& Tutorial::operator=(const Tutorial &tutorial) {
    /**
     * Assignment operator
     */
    title = tutorial.getTitle();
    presenter = tutorial.getPresenter();
    duration = tutorial.getDuration();
    likes = tutorial.getLikes();
    link = tutorial.getLink();
}

istream& operator>>(istream& stream, Tutorial& tutorial) {
    string dur;
    string like;

    stream>>tutorial.title;
    stream>>tutorial.presenter;
    stream>>dur;
    stream>>like;
    stream>>tutorial.link;

    sscanf(dur.c_str(), "%d", &(tutorial.duration)); // NOLINT
    sscanf(like.c_str(), "%d", &(tutorial.likes));  //NOLINT


}

ostream& operator<<(ostream& stream, const Tutorial& tutorial) {
    string dur = to_string(tutorial.duration);
    string like = to_string (tutorial.likes);

    stream<<tutorial.title;
    stream<<string(",");
    stream<<tutorial.presenter;
    stream<<string(",");
    stream<<dur;
    stream<<string(",");
    stream<<like;
    stream<<string(",");
    stream<<tutorial.link;
    stream<<"\n";
}

string Tutorial::getFormattedDuration() {
    string output = "";
    output+=to_string(this->duration/60) + "m";
    output+=to_string(this->duration%60) + "s";
    return output;
}
