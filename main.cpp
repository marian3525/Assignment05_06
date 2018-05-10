#include <iostream>
#include <fstream>
#include "tests/test.h"
#include "ui/cli.h"
#include "Writers/HTMLWriter.h"

using namespace std;

void run() {

    Controller controller{};
    CLI cli{controller};
    cli.start();
}

void test() {
    Test::test();
}

int main() {
    //test();
    run();
    return 0;
};