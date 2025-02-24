
// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> read_int() {
    /* Example input.txt
    3
    1 2 3
    3 4 5
    */
    int n = 0;
    vector<int> inp;
    cin >> n;
    int temp;
    while (n--) {
        cin >> temp;
        inp.push_back(temp);
    }
    // inp is the array of strings
    return inp;
}

vector<int> read_int(int n) {
    vector<int> inp;
    // cin >> n;
    int temp;
    while (n--) {
        cin >> temp;
        inp.push_back(temp);
    }
    // inp is the array of strings
    return inp;
}