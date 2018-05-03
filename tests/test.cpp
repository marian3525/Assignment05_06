//
// Created by Marian on 3/29/2018.
//

#include "test.h"
#include "../domain/tutorial.h"
#include "../Validator/Validator.h"
#include "../repository/repository.h"
#include "../controller/controller.h"
#include "../Exceptions/ValidatorException.h"
#include "../Exceptions/ControllerException.h"
#include <cassert>
#include <iostream>

void Test::testDomain() {
    Tutorial* t = new Tutorial("title","presenter", 20, 13, "link");

    assert(t->getTitle()=="title");
    assert(t->getPresenter()=="presenter");
    assert(t->getDuration() == 20);
    assert(t->getLikes() == 13);
    assert(t->getLink()=="link");

    delete t;
}


void Test::testValidator() {
    try {
        Validator::validateAdd("title", "presenter", 10, 1, "link");
    }
    catch (ValidatorException& e) {
        assert(false);
    }

    try {
        Validator::validateAdd("", "presenter", 10, 1, "link");
        assert(false);
    }
    catch (ValidatorException& e) {
    }

    try {
        Validator::validateAdd("title", "", 10, 1, "link");
        assert(false);
    }
    catch (ValidatorException& e) {
    }
    try {
        Validator::validateAdd("title", "presenter", 0, 1, "link");
        assert(false);
    }
    catch (ValidatorException& e) {
    }
    try {
        Validator::validateAdd("title", "presenter", 10, -1, "link");
        assert(false);
    }
    catch (ValidatorException& e) {
    }
    try {
        Validator::validateAdd("title", "presenter", 10, 1, "");
        assert(false);
    }
    catch (ValidatorException& e) {
    }
}

void  Test::testRepo() {
    Repository repo{true};

    assert(repo.getSize() == 0);

    Tutorial t{"title1","presenter1", 20, 13, "link1"};
    Tutorial t1{"title2","presenter2", 20, 13, "link2"};
    Tutorial t2{"title3","presenter3", 20, 13, "link3"};

    repo.add(t);
    /*
    assert(repo.getSize()==1);
    assert(repo[0] == t);

    repo.add(t1);
    assert(repo.getSize() == 2);
    assert(repo[1] == t1);
    assert(!(repo[1] == t2));

    repo.add(t2);
    assert(repo.getSize() == 1);
    assert(repo[2] == t2);
    assert(!(repo[2] == t1));
*/

    //remove
    //repo.remove("title2");
    //assert(repo.getSize() == 2);
    //assert(repo[1] == t2);
}

void testAdd() {
    Repository repository{true};
    Controller controller{};

    assert(repository.getSize() == 10);
    controller.addTutorial("title1","presenter1", 20, 13, "link1");

    assert(repository.getSize()==11);

    assert(repository[10].getTitle() == string("title1"));

    try {
        controller.addTutorial("","presenter1", 20, 13, "link1");
    }
    catch(ValidatorException& ve) {
        assert(ve.getMessage() == "Title is empty!\n");
    }

    delete &controller;
    delete &repository;
}

void testRemove() {
    Repository repository{true};
    Controller controller{};

    assert(repository.getSize() == 10);
    controller.addTutorial("title1","presenter1", 20, 13, "link1");
    assert(repository.getSize()==11);
    controller.removeTutorial("title1");
    assert(repository.getSize() == 10);

    try {
        controller.removeTutorial("");
    }
    catch(ControllerException& ce) {
        assert(ce.getMessage() == "Element doesn't exist");
    }
    assert(repository.getSize() == 10);
}

void testGetPrintable() {
    Repository repo{true};
    Controller controller{};

    vector<string> output;
    int n;
    output = controller.getAllPrintable();

    vector<Tutorial> all =  repo.getAll();

    for(int i=0; i<repo.getSize(); i++) {
        assert(output[i] == all[i].toString());
    }

    delete &controller;
}

void testUpdate() {
    Repository repo{true};
    Controller controller{};
    int n;

    assert(repo[0].getTitle() == string("OOP"));
    assert(repo[0].getPresenter() == string("Iuliana Bocicor"));
    assert(repo[0].getDuration() == 7000);
    assert(repo[0].getLikes() == 110);
    assert(repo[0].getLink() == string("link1"));

    controller.updateTutorial(string("OOP"), string("newPresenter"), 1, 2, string("newLink"));

    assert(repo[0].getTitle() == string("OOP"));
    assert(repo[0].getPresenter() == string("newPresenter"));
    assert(repo[0].getDuration() == 1);
    assert(repo[0].getLikes() == 2);
    assert(repo[0].getLink() == string("newLink"));
}

void testFilterByPresenter() {
    Repository repo{true};
    Controller controller{};
    int n;

    vector<Tutorial> results = controller.filterByPresenter(string("Rares"));
    assert(results.size() == 1);
    assert(results[0].getTitle() == string("OS"));
    assert(results[0].getDuration() == 6411);

    results = controller.filterByPresenter(string(""));
    assert(results.size()==repo.getSize());
    for(int i=0; i<results.size(); i++) {
        assert(results[i].getTitle() == repo[i].getTitle());
    }
}

void Test::testLikeTutorial() {
    Repository repo{true};
    Controller controller{};
    int n;
    vector<Tutorial> t;

    controller.addToWatchList("OOP");
    t = controller.getWatchList();
    assert(t.size()==1);
    assert(t[0].getTitle() == "OOP");
    assert(t[0].getDuration() == 7000);

    controller.addToWatchList("OS");
    t = controller.getWatchList();
    assert(t.size()==2);
    assert(t[0].getTitle() == "OOP");
    assert(t[1].getTitle() == "OS");

    delete &controller;
    delete &repo;
}

void Test::testDeleteFromWatchList() {
    Repository repo{true};
    Controller controller{};
    int n;
    vector<Tutorial> t;

    controller.addToWatchList("OOP");
    t = controller.getWatchList();
    assert(t.size()==1);
    assert(t[0].getTitle() == "OOP");
    assert(t[0].getDuration() == 7000);

    controller.addToWatchList("OS");
    t = controller.getWatchList();
    assert(t.size()==2);
    assert(t[0].getTitle() == "OOP");
    assert(t[1].getTitle() == "OS");

    controller.deleteFromWatchlist("OOP");
    t = controller.getWatchList();
    assert(t.size()==1);
    assert(t[0].getTitle() == "OS");

    controller.deleteFromWatchlist("OS");
    t = controller.getWatchList();
    assert(empty(t) == true);

    delete &controller;
    delete &repo;
}

void Test::testGetWatchList() {
    Repository repo{true};
    Controller controller{};
    int n;
    vector<Tutorial> t;

    controller.addToWatchList("OOP");
    t = controller.getWatchList();
    assert(t.size()==1);
    assert(t[0].getTitle() == "OOP");
    assert(t[0].getDuration() == 7000);

    controller.addToWatchList("OS");
    t = controller.getWatchList();
    assert(t.size()==2);
    assert(t[0].getTitle() == "OOP");
    assert(t[1].getTitle() == "OS");

    controller.deleteFromWatchlist("OOP");
    t = controller.getWatchList();
    assert(t.size()==1);
    assert(t[0].getTitle() == "OS");
}

void Test::testAddToWatchList() {
    Repository repo{true};
    Controller controller{};
    int n;
    vector<Tutorial> t;

    controller.addToWatchList("OOP");
    t = controller.getWatchList();
    assert(t.size()==1);
    assert(t[0].getTitle() == "OOP");
    assert(t[0].getDuration() == 7000);

    controller.addToWatchList("OS");
    t = controller.getWatchList();
    assert(t.size()==2);
    assert(t[0].getTitle() == "OOP");
     assert(t[1].getTitle() == "OS");
    delete &controller;
    delete &repo;
}

void Test::testController() {
    //admin functions
    testAdd();
    testRemove();
    testUpdate();
    testGetPrintable();

    //user functions
    testFilterByPresenter();
    testAddToWatchList();
    testGetWatchList();
    testDeleteFromWatchList();
    testLikeTutorial();
}

void Test::test() {
    //testDomain();
    //testValidator();
    testRepo();
    //testController();
}