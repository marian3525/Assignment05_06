#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "../controller/controller.h"
#include "cli.h"

char *getInput() {
    /**
     * Read user input from the keyboard
     * Returns the read string or "" if an endline char is read
     */
    char *input = (char*) malloc(100 * sizeof(char));
    fgets(input, 100, stdin);
    if (strcmp(input, "\n") == 0) {
        input = "";
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

CLI::CLI(Controller* controller) {
    this->controller = controller;
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
     delete aux;
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
    delete aux;
    return minutes;
}

void CLI::showResults(Tutorial **results, int n) {
    /**
     * Show each tutorial in the result list and offer the option to like or go to the next
     * Continue until the user enters "done". If the end of the list is reached, "next" will provide the first tutorial
     * in the list
     * @param results: list of tutorials
     * @param n: number of tutorials in the list
     * @return None
     */
     int index = 0;
     string response;
     if(n>0) {
         do {
             cout<<results[index]->toString();
             cin>>response;
             if(response == "like") {
                this->controller->likeTutorial(results[index]->getTitle());
                 cout<<"Liked. Add to watchlist?"<<endl;
                 cin>>response;
                 if(response == "add")
                     //add the tutorial to the watch list if not added already

                     if(this->controller->addToWatchList(results[index]->getTitle())==0) {
                         cout<<"Tutorial added to your watchlist"<<endl;
                     }
                     else {
                         cout<<"The current tutorial was already added to your watchlist"<<endl;
                     }
             }
             if(response == "next") {
                 index++;
             }
             if(response == "done") {
                 break;
             }
             if(index == n) {
                 index = 0;
             }
         }while(true);
     }
     else {
         cout<<"No tutorials"<<endl;
     }
     delete[] results;
     cin.get();  //???
}

void CLI::start() {
    char *command;
    char *input;
    char **params;
    bool stopped = false;
    int paramNumber = 0;
    char **auxPtr;
    bool adminMode = false;

    while(not stopped) {
        if(adminMode) {
            printf("(admin)");
        }
        else {
            printf("(user)");
        }
        printf(">>>");

        input = getInput();
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
            if(strcmp(command, "add") == 0) {
                //add a tutorial
                //add <title> <presenter> <duration: xmys> <likes> <link>
                string title, presenter, link;
                int duration, likes;
                title = string(params[0]);
                presenter = params[1];
                duration = getMinutes(params[2])*60 + getSeconds(params[2]);
                sscanf(params[3], "%d", &likes);
                link = params[4];
                this->controller->addTutorial(title, presenter, duration, likes, link);
            }
            if(strcmp(command, "remove") ==0) {
                //remove <tutorial_title>
                string title = params[0];
                this->controller->removeTutorial(title);
            }
            if(strcmp(command, "update") == 0) {
                string title, presenter, link;
                int duration, likes;
                title = string(params[0]);
                presenter = params[1];
                duration = getMinutes(params[2])*60 + getSeconds(params[2]);
                sscanf(params[3], "%d", &likes);
                link = params[4];
                this->controller->updateTutorial(title, presenter, duration, likes, link);
            }
            if(strcmp(command, "print") == 0) {
                string* output;
                int n;
                output = this->controller->getAllPrintable(n);
                for(int i=0; i<n; i++) {
                    cout<<output[i]<<endl;
                }
            }
        }
        else {
            //user features
            if(strcmp(command, "filter") == 0) {
                //filter "presenterName"
                string name;
                if(paramNumber > 0) {
                    if(paramNumber == 2)
                        name = string(params[0]) + string(" ") + string(params[1]);
                    if(paramNumber == 1) {
                        name = string(params[0]);
                    }
                    int n;
                    Tutorial** results = this->controller->filterByPresenter(name, n);

                    showResults(results, n);
                }
                else {
                    int n;
                    Tutorial** results = this->controller->filterByPresenter(string(""), n);

                    showResults(results, n);
                }
            }
            if(strcmp(command, "remove") == 0) {
                this->controller->deleteFromWatchlist(params[0]);
            }
            if(strcmp(command, "print")==0) {
                cout<<"Watch list:"<<endl;
                int n = 0;
                Tutorial** tutorials = this->controller->getWatchList(n);
                if(n==0) {
                    cout<<"Your watch list is empty!"<<endl;
                }
                else {
                    for (int i = 0; i < n; i++) {
                        cout << tutorials[i]->toString() << endl;
                    }
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

CLI::~CLI() {
}
