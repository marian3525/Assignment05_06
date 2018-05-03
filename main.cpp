#include <iostream>
#include <fstream>
#include "tests/test.h"
#include "ui/cli.h"

using namespace std;

void run() {
    Controller controller{};
    CLI cli{controller};
    cli.start();

    delete &cli;
    //delete &controller;
}

void test() {
    Test::test();
}

int main() {
    //test();
    run();
    /*
    Tutorial t{"nume", "presenter", 1000, 23, "linky"};
    ofstream ofstream1("data.stuff");
    ofstream1<<t;
    //ofstream1<<123;
    ofstream1.close();
     */
    return 3;
};