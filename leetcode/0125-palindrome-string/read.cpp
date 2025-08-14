#include <bits/stdc++.h>
using namespace std;
void read_input(const string& filePath) {
    if (!freopen(filePath.c_str(), "r", stdin)) {
        cout << "There was a problem opening the input file";
        exit(1);
    }
}