#include <string.h>

#include <iostream>
using namespace std;
void file_as_stdin(const string& filePath) {
    if (!freopen(filePath.c_str(), "r", stdin)) {
        cout << "There was a problem opening the input file";
        exit(1);
    }
}