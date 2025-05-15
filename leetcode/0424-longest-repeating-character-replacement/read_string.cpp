// #include <bits/stdc++.h>

// #include "./read.cpp"
#include <string.h>

#include <iostream>
#include <vector>

using namespace std;

vector<string> read_string() {
    // input.txt as stdin
    // read_input(filePath.c_str());
    // Read strings of arrays

    /* Example input.txt
    6
    eat
    tea
    tan
    ate
    nat
    bat
     */
    int n = 0;
    vector<string> inp;
    cin >> n;
    string temp;
    getline(cin, temp);
    while (n--) {
        getline(cin, temp);
        inp.push_back(temp);
    }

    // inp is the array of strings
    return inp;
}
