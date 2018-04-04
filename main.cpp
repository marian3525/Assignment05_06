

#include "tests/test.h"
#include "ui/cli.h"

void run() {
    Repository* repo = new Repository();
    Controller* controller = new Controller(repo);
    CLI* cli = new CLI(controller);
    cli->start();

    delete cli;
    delete controller;
    delete repo;
}

void test() {
    Test::test();
}

int main() {
    test();
    run();
    return 3;
}