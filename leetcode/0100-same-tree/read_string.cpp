
// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

vector<string> read_string() {
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
