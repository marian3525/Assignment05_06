//
// Created by Marian on 3/29/2018.
//

#include "test.h"
#include "../domain/tutorial.h"
#include "../Validator/Validator.h"
#include "../repository/DynamicVector.h"
#include "../repository/repository.h"
#include "../controller/controller.h"
#include "../repository/TemplateDynamicVector.h"
#include <assert.h>
#include <cstring>

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
    assert(Validator::validateAdd("title", "presenter", 10, 1, "link") == 0);
    assert(Validator::validateAdd("", "presenter", 10, 1, "link") == 1);
    assert(Validator::validateAdd("title", "", 10, 1, "link") == 2);
    assert(Validator::validateAdd("title", "presenter", 0, 1, "link") == 3);
    assert(Validator::validateAdd("title", "presenter", 10, -1, "link") == 4);
    assert(Validator::validateAdd("title", "presenter", 10, 1, "") == 5);
}

void Test::testDynamicVector() {
    DynamicVector* v = new DynamicVector(10);
    Tutorial* t = new Tutorial("title","presenter", 20, 13, "link");
    v->add(t);
    assert(v->getSize() == 1);
    Tutorial* t1 = new Tutorial("title1","presenter1", 20, 13, "link1");
    v->add(t1);
    assert(v->getSize() == 2);
    Tutorial* t2 = new Tutorial("title1","presenter1", 20, 13, "link1");

    assert(v->exists(t) == true);
    assert(v->exists(t1) == true);
    assert(v->exists(t2) == false);
    v->remove(t);
    assert(t1 != t);
    assert(v->getSize() == 1);
    *v-t1;
    assert(v->getSize() == 0);

    delete v; //doesn't crash on destruction here
    delete t;
    delete t1;
    delete t2;

    //tests for the template dyn. vector
    TemplateDynamicVector<Tutorial>* vt = new TemplateDynamicVector<Tutorial>(10);
    Tutorial* tv = new Tutorial("title","presenter", 20, 13, "link");
    vt->add(t);
    assert(vt->getSize() == 1);
    Tutorial* t1v = new Tutorial("title1","presenter1", 20, 13, "link1");
    vt->add(t1);
    assert(vt->getSize() == 2);
    Tutorial* t2v = new Tutorial("title1","presenter1", 20, 13, "link1");

    assert(vt->exists(t) == true);
    assert(vt->exists(t1) == true);
    assert(vt->exists(t2) == false);
    vt->remove(tv);
    assert(t1v != tv);
    assert(vt->getSize() == 1);
    *vt-t1v;
    assert(vt->getSize() == 0);

    delete vt; //doesn't crash on destruction here
    delete t1v;
    delete t2v;
}

void  Test::testRepo() {
    Repository* repo = new Repository();

    assert(repo->getSize() == 0);

    Tutorial* t = new Tutorial("title1","presenter1", 20, 13, "link1");
    Tutorial* t1 = new Tutorial("title2","presenter2", 20, 13, "link2");
    Tutorial* t2 = new Tutorial("title3","presenter3", 20, 13, "link3");

    repo->add(t);
    assert(repo->getSize()==1);
    assert((*repo)[0] == *t);

    repo->add(t1);
    assert(repo->getSize() == 2);
    assert((*repo)[1] == *t1);
    assert(!((*repo)[1] == *t2));

    repo->add(t2);
    assert(repo->getSize() == 3);
    assert((*repo)[2] == *t2);
    assert(!((*repo)[2] == *t1));

    //remove
    repo->remove("title2");
    assert(repo->getSize() == 2);
    assert((*repo)[1] == *t2);

    //delete repo;   //double call on the destructor of the Dyn. Vector and crash
}

void testAdd() {
    Repository* repository = new Repository();
    Controller* controller = new Controller(repository);

    assert(repository->getSize() == 6);
    controller->addTutorial("title1","presenter1", 20, 13, "link1");
    assert(repository->getSize()==7);
    assert((*repository)[6].getTitle() == string("title1"));
    assert(controller->addTutorial("","presenter1", 20, 13, "link1") == 1);
    delete controller;
    delete repository;
}

void testRemove() {
    Repository* repository = new Repository();
    Controller* controller = new Controller(repository);

    assert(repository->getSize() == 6);
    controller->addTutorial("title1","presenter1", 20, 13, "link1");
    assert(repository->getSize()==7);
    controller->removeTutorial("title1");
    assert(repository->getSize() == 6);

    assert(controller->removeTutorial("") == 1);
    assert(repository->getSize() == 6);
}

void testGetPrintable() {
    Repository* repo = new Repository();
    Controller* controller = new Controller(repo);

    string* output;
    int n;
    output = controller->getAllPrintable(n);

    Tutorial** all =  repo->getAll();

    for(int i=0; i<repo->getSize(); i++) {
        assert(output[i] == all[i]->toString());
    }

    for(int i=0; i<repo->getSize(); i++) {
        delete all[i];
    }
    delete controller;
    delete[] output;
    delete[] all;
}

void testUpdate() {
    Repository* repo = new Repository();
    Controller* controller = new Controller(repo);
    int n;

    assert((*repo)[0].getTitle() == string("OOP"));
    assert((*repo)[0].getPresenter() == string("Iuliana Bocicor"));
    assert((*repo)[0].getDuration() == 7000);
    assert((*repo)[0].getLikes() == 110);
    assert((*repo)[0].getLink() == string("link1"));

    controller->updateTutorial(string("OOP"), string("newPresenter"), 1, 2, string("newLink"));

    assert((*repo)[0].getTitle() == string("OOP"));
    assert((*repo)[0].getPresenter() == string("newPresenter"));
    assert((*repo)[0].getDuration() == 1);
    assert((*repo)[0].getLikes() == 2);
    assert((*repo)[0].getLink() == string("newLink"));

}

void testFilterByPresenter() {
    Repository* repo = new Repository();
    Controller* controller = new Controller(repo);
    int n;

    Tutorial** results = controller->filterByPresenter(string("Rares"), n);
    assert(n==1);
    assert(results[0]->getTitle() == string("OS"));
    assert(results[0]->getDuration() == 6411);

    results = controller->filterByPresenter(string(""), n);
    assert(n==repo->getSize());
    for(int i=0; i<n; i++) {
        assert(results[i]->getTitle() == (*repo)[i].getTitle());
    }
}

void Test::testLikeTutorial() {
    Repository* repo = new Repository();
    Controller* controller = new Controller(repo);
    int n;
    Tutorial** t;

    controller->addToWatchList("OOP");
    t = controller->getWatchList(n);
    assert(n==1);
    assert(t[0]->getTitle() == "OOP");
    assert(t[0]->getDuration() == 7000);

    controller->addToWatchList("OS");
    delete[] t;
    t = controller->getWatchList(n);
    assert(n==2);
    assert(t[0]->getTitle() == "OOP");
    assert(t[1]->getTitle() == "OS");

    delete[] t;
    delete controller;
    delete repo;
}

void Test::testDeleteFromWatchList() {
    Repository* repo = new Repository();
    Controller* controller = new Controller(repo);
    int n;
    Tutorial** t;

    controller->addToWatchList("OOP");
    t = controller->getWatchList(n);
    assert(n==1);
    assert(t[0]->getTitle() == "OOP");
    assert(t[0]->getDuration() == 7000);

    controller->addToWatchList("OS");
    delete[] t;
    t = controller->getWatchList(n);
    assert(n==2);
    assert(t[0]->getTitle() == "OOP");
    assert(t[1]->getTitle() == "OS");

    controller->deleteFromWatchlist("OOP");
    t = controller->getWatchList(n);
    assert(n==1);
    assert(t[0]->getTitle() == "OS");
    delete[] t;

    controller->deleteFromWatchlist("OS");
    t = controller->getWatchList(n);
    assert(n==0);

    delete[] t;
    delete controller;
    delete repo;
}

void Test::testGetWatchList() {
    Repository* repo = new Repository();
    Controller* controller = new Controller(repo);
    int n;
    Tutorial** t;

    controller->addToWatchList("OOP");
    t = controller->getWatchList(n);
    assert(n==1);
    assert(t[0]->getTitle() == "OOP");
    assert(t[0]->getDuration() == 7000);

    controller->addToWatchList("OS");
    delete[] t;
    t = controller->getWatchList(n);
    assert(n==2);
    assert(t[0]->getTitle() == "OOP");
    assert(t[1]->getTitle() == "OS");

    controller->deleteFromWatchlist("OOP");
    t = controller->getWatchList(n);
    assert(n==1);
    assert(t[0]->getTitle() == "OS");
    delete[] t;
}

void Test::testAddToWatchList() {
    Repository* repo = new Repository();
    Controller* controller = new Controller(repo);
    int n;
    Tutorial** t;

    controller->addToWatchList("OOP");
    t = controller->getWatchList(n);
    assert(n==1);
    assert(t[0]->getTitle() == "OOP");
    assert(t[0]->getDuration() == 7000);

    controller->addToWatchList("OS");
    delete[] t;
    t = controller->getWatchList(n);
    assert(n==2);
    assert(t[0]->getTitle() == "OOP");
    assert(t[1]->getTitle() == "OS");
    delete[] t;
    delete controller;
    delete repo;
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
    testDomain();
    testValidator();
    testDynamicVector();
    testRepo();
    testController();
}

