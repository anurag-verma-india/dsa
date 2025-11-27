
// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

vector<string> read_int_as_string() {
    int n = 0;
    vector<string> inp;
    cin >> n;
    string temp;
    while (n--) {
        cin >> temp;
        inp.push_back(temp);
    }
    // inp is the array of ints
    return inp;
}

vector<int> read_int() {
    // input.txt as stdin
    // if (!freopen("input.txt", "r", stdin)) {
    //     cout << "There was a problem opening the input file";
    //     exit(1);
    // }
    // Read array from stdin

    /* Example input.txt
    7
    4 1 -1 2 -1 2 3
    */
    int n = 0;
    vector<int> inp;
    cin >> n;
    int temp;
    while (n--) {
        cin >> temp;
        inp.push_back(temp);
    }
    // inp is the array of ints
    return inp;
}


vector<int> read_int(int n) {
    /*
    Example input when this function is called (Assuming it's called like this: read_int(3))
    1 2 3
    */
    vector<int> inp;
    // cin >> n;
    int temp;
    while (n--) {
        cin >> temp;
        inp.push_back(temp);
    }
    // inp is the array of ints
    return inp;
}