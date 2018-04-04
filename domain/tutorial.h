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
public:
    void setPresenter(string presenter);

    void setDuration(int duration);

    void setLikes(int likes);
    void incLikes();

    void setLink(string link);

    string toString();
    //default constructor
    Tutorial(string title, string presenter, int duration, int likes, string link);

    //copy constructor
    Tutorial(const Tutorial& t);

    //destructor
    ~Tutorial();

    bool operator==(const Tutorial& tutorial);
    void operator=(const Tutorial& tutorial);
    string getTitle()const;
    string getPresenter()const;
    int getDuration()const;
    int getLikes()const;
    string getLink()const;

};


#endif //ASSIGNMENT05_06_TUTORIAL_H
