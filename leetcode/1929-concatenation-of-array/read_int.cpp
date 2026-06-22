#include <iostream>
#include <vector>
using namespace std;

vector<int> read_int() {
    int n = 0, temp = 0;
    vector<int> inp;
    cin >> n;
    while (n--) {
        cin >> temp;
        inp.push_back(temp);
    }
    return inp;
}