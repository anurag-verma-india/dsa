
// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

vector<string> read_int() {
    /* Example input.txt
    8
    4 1 -1 2 -1 2 3 null
    */
    int n = 0;
    vector<string> inp;
    cin >> n;
    string temp;
    while (n--) {
        cin >> temp;
        inp.push_back(temp);
    }
    return inp;
}
