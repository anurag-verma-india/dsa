#include <string.h>

#include <iostream>

using namespace std;

void file_as_stdin(const string& file_path) {
    if (!freopen(file_path.c_str(), "r", stdin)) {
        cout << "There was a problem opening the input file: " << file_path << endl;
        exit(1);
    }
}