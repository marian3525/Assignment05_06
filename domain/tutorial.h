//
// Created by Marian on 3/28/2018.
//

#ifndef ASSIGNMENT05_06_TUTORIAL_H
#define ASSIGNMENT05_06_TUTORIAL_H

#include <string>
using namespace std;

class Tutorial {
private:
    string title;
    string presenter;
    int duration; //in seconds
    int likes;
    std::string link;  //link to the resource
    string durationToString(int duration);
    string likesToString(int likes);
public:
    void setPresenter(string presenter);

    void setDuration(int duration);

    void setLikes(int likes);
    void incLikes();

    void setLink(string link);

    const string toString() const ;

    string getFormattedDuration();
    //default constructor
    Tutorial(string title, string presenter, int duration, int likes, string link);

    //copy constructor
    Tutorial(const Tutorial& t);

    //destructor
    ~Tutorial();

    bool operator==(const Tutorial& tutorial);
    Tutorial& operator=(const Tutorial& tutorial);
    string getTitle()const;
    string getPresenter()const;
    int getDuration()const;
    int getLikes()const;
    string getLink()const;

    friend istream& operator>>(istream& stream, Tutorial& tutorial);
    friend ostream& operator<<(ostream& stream, const Tutorial& tutorial);

};


#endif //ASSIGNMENT05_06_TUTORIAL_H
