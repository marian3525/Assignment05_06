//
// Created by Marian on 5/3/2018.
//

#include "CSVWriter.h"
#include "../domain/tutorial.h"
#include "../repository/repository.h"
#include <Windows.h>
#include <fstream>
#include <vector>

void CSVWriter::write(Repository& repo) {
    vector<Tutorial> all = repo.getAll();
    ofstream ofstream1("watchlist.csv");
    for(const auto& t:all) {
        ofstream1<<t;
    }
    //for_each(all.begin(), all.end(), [&ofstream1](Tutorial& t){ofstream1<<t;});
    ofstream1.close();

    HWND hwnd = GetDesktopWindow();
    ShellExecute(hwnd, NULL, "notepad.exe", "D:/CS/OOP/Assignment05-06/cmake-build-debug-cygwin/watchlist.csv", NULL, SW_MAXIMIZE);
}

CSVWriter::CSVWriter() {

}
