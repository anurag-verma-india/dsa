
#include <iostream>
#include <vector>
using namespace std;

vector<int> read_int() {

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
    // inp is the array of strings
    return inp;
}