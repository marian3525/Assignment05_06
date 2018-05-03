#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include "../controller/controller.h"
#include "cli.h"
#include "../Exceptions/ControllerException.h"
#include "../Exceptions/ValidatorException.h"
#include "../Exceptions/RepositoryException.h"
#include <Windows.h>

char *getInput() {
    /**
     * Read user input from the keyboard
     * Returns the read string or "" if an endline char is read
     */
    char *input = (char*) malloc(100 * sizeof(char));
    fgets(input, 100, stdin);
    if (strcmp(input, "\n") == 0) {
        free(input);
        return "";
    }
    return strtok(input, "\n");
}

char *getCommand(char *input) {
    /**
     * Extracts and returns the command from a input string (without the endline char)
     */
    if (input == NULL) {
        return NULL;
    }
    char *copy = strdup(input);
    if (strchr(input, ' ') == NULL) { //single word commnad, e.g. print
        return strtok(copy, "\n");
    }

    char *result = strtok(copy, " ");
    return result;
}

char **getParams(char *input, int *paramNumber) {
    /**
     * Extracts the params and returns a list of pointers to them
     * paramNumber: number of params parsed
     */
    *paramNumber = 0; //in case it was not initialised
    char **result = (char**) malloc(10 * sizeof(char *));  //assuming each command has at most 10 params
    char *param;
    char *copy = strdup(input);
    free(input);

    int index = 0;

    param = strtok(copy, " "); //getting rid of the command
    param = strtok(NULL, " "); //getting 1st param

    while (param != NULL) { //parsing params
        //result[index] = malloc(20 * sizeof(char));  //assuming each param has at most 20 chars
        result[index++] = strdup(param);
        param = strtok(NULL, " ");
    }
    *paramNumber = index;
    free(copy);
    free(param);
    return result;
}

int CLI::getMinutes(string s) {
    /**
     * s: string in the format xmys, where x and y are integers
     * Return the number of minutes as an int
     */
     size_t endPosition = s.find("m");
     int minutes;
     char* aux = new char[endPosition+1];
     //put the substr. with the number of minutes in the aux string
     s.copy(aux, endPosition, 0);  //copy endPosition chars starting from 0
     aux[endPosition]=0;
     sscanf(aux, "%d", &minutes);
     delete[] aux;
     return minutes;
}

int CLI::getSeconds(string s) {
    /**
     * s: string in the format xmys, where x and y are integers
     * Return the number of seconds as an int
     */
    size_t endPosition = s.find("s");
    size_t startPosition = s.find("m")+1;
    int minutes;
    //12m30s
    //012345
    char* aux = new char[endPosition-startPosition+1];
    //put the substr. with the number of seconds in the aux string
    s.copy(aux, endPosition-startPosition, startPosition);
    aux[endPosition-startPosition] = 0;
    sscanf(aux, "%d", &minutes);
    delete[] aux;
    return minutes;
}

void CLI::showResults(vector<Tutorial> results, string name) {
    /**
     * Show each tutorial in the result list and offer the option to like or go to the next
     * Continue until the user enters "done". If the end of the list is reached, "next" will provide the first tutorial
     * in the list
     * @param results: list of tutorials
     * @param name: The name the results were filtered by
     * @param n: number of tutorials in the list
     * @return None
     */
     int index = 0;
     string response;
     if(!results.empty()) {
         do {
             cout<<results[index].toString();
             cout<<"Did you enjoy this tutorial? (yes/no or done to exit the submenu)"<<endl;
             cin>>response;

             if(response == "yes") {
                this->controller.likeTutorial(results[index].getTitle());
                results = controller.filterByPresenter(name);    //reload the tutorials with the updated likes
                 cout<<"Liked. Add to watchlist?"<<endl;
                 cin>>response;
                 if(response == "yes" or response=="add")
                     //add the tutorial to the watch list if not added already

                     try {
                        this->controller.addToWatchList(results[index].getTitle());
                        cout<<"Tutorial added to your watchlist"<<endl;
                     }
                     catch(ControllerException& ce) {
                         cout<<"The current tutorial was already added to your watchlist"<<endl;
                     }
             }
             if(response == "no") {
                 cout<<"Too bad. Maybe the next one will be more interesting"<<endl;
             }
             if(response == "next") {
                 index++;
             }
             if(response == "done") {
                 break;
             }
             if(index == results.size()) {
                 cout<<"Starting from the beginning of the list:"<<endl;
                 index = 0;
             }
         }
         while(true);
     }
     else {
         cout<<"No tutorials"<<endl;
     }
     cin.get();  //???
}

void CLI::start() {
    char *command;
    char *input;
    char **params;
    bool stopped = false;
    int paramNumber = 0;
    bool adminMode = false;
    string mode="";

    do {
        cout << "html or csv mode for the watchlist?" << endl;
        cin >> mode;
    }
    while(mode != "html" and mode != "csv");

    while(not stopped) {
        if(adminMode) {
            cout<<"(admin)";
        }
        else {
            cout<<"(user)";
        }
        printf(">>>");

        input = getInput();
        if(strcmp(input, "") == 0) {
            continue;
        }
        command = getCommand(input);
        params = getParams(input, &paramNumber);

        if(strcmp(command, "exit")==0) {
            stopped = true;
        }

        if(strcmp(command, "toadmin") == 0) {
            adminMode = true;
        }
        if(strcmp(command, "touser") == 0) {
            adminMode = false;
        }
        if(adminMode) {
            //admin features
            if(strcmp(command, "add") == 0) { //no leaks
                //add a tutorial
                //add <title> <presenter> <duration: xmys> <likes> <link>
                string title, presenter, link;
                int duration, likes;
                
                title = string(params[0]);
                presenter = params[1];
                duration = getMinutes(params[2])*60 + getSeconds(params[2]);

                sscanf(params[3], "%d", &likes);

                link = params[4];
                try {
                    this->controller.addTutorial(title, presenter, duration, likes, link);
                }
                catch(const ValidatorException& ve) {
                    cout<<ve.getMessage();
                }
            }
            if(strcmp(command, "remove") ==0) {  //no leaks
                //remove <tutorial_title>
                string title = params[0];
                try {
                    this->controller.removeTutorial(title);
                }
                catch(const ControllerException& ce) {
                    cout<<ce.getMessage();
                }
                catch(const ValidatorException& ve) {
                    cout<<ve.getMessage();
                }
            }
            if(strcmp(command, "update") == 0) { //no leaks
                string title, presenter, link;
                int duration, likes;
                title = string(params[0]);
                presenter = params[1];
                duration = getMinutes(params[2])*60 + getSeconds(params[2]);
                sscanf(params[3], "%d", &likes);
                link = params[4];
                try {
                    this->controller.updateTutorial(title, presenter, duration, likes, link);
                }
                catch(const ControllerException& ce) {
                    cout<<ce.getMessage();
                }
                catch(const ValidatorException& ve) {
                    cout<<ve.getMessage();
                }
            }
            if(strcmp(command, "print") == 0) { //no leaks
                vector<string> output = this->controller.getAllPrintable();
                for(const string &current:output)
                    cout<<current, cout<<endl;
            }
        }
        else {
            //user features

            if(strcmp(command, "watch") == 0) {
                if(mode=="html") {
                    controller.dumpHTMLString();
                }
                if(mode=="csv") {
                    controller.dumpCSVString();
                }
            }

            if(strcmp(command, "filter") == 0) {
                //filter "presenterName"
                string name;
                if(paramNumber > 0) {
                    if(paramNumber == 2)
                        name = string(params[0]) + string(" ") + string(params[1]);
                    if(paramNumber == 1) {
                        name = string(params[0]);
                    }

                    vector<Tutorial> results = this->controller.filterByPresenter(name);

                    showResults(results, name);
                }
                else {
                    vector<Tutorial> results = this->controller.filterByPresenter(string(""));

                    showResults(results, "");
                }
            }
            if(strcmp(command, "remove") == 0) {
                try {
                    this->controller.deleteFromWatchlist(params[0]);
                }
                catch(const RepositoryException& re) {
                    cout<<re.getMessage();
                }
            }
            if(strcmp(command, "print")==0) { //no leaks
                cout<<"Watch list:"<<endl;
                vector<Tutorial> tutorials = this->controller.getWatchList();
                if(tutorials.empty()) {
                    cout<<"Your watch list is empty!"<<endl;
                }
                else {

                    for (const auto &tutorial:tutorials) {
                        cout << tutorial.toString() << endl;
                    }
                }
            }
        }
        for(int i=0; i<paramNumber; i++) {
            free(params[i]);
        }
        free(params);
        free(command);
    }
}

CLI::~CLI() {
    delete &controller;
}
