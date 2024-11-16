// https://www.geeksforgeeks.org/switch-statement-in-cpp/

#include <bits/stdc++.h>
using namespace std;

int main() {
    // declarations
    int n;
    vector<string> s;
    vector<int> sn;

    // inputs
    cin >> n;
    // up down left right
    // 0 1 2 3
    while (n--) {
        string tmp;
        cin >> tmp;
        s.push_back(tmp);
        if (tmp == "up")
            sn.push_back(0);
        else if (tmp == "down")
            sn.push_back(1);
        else if (tmp == "left")
            sn.push_back(2);
        else if (tmp == "right")
            sn.push_back(3);
    }

    // Operations
    int left = 5;
    int right = 5;
    int moves = 0;
    for (int i = 0; i < n; i++) {
        if (left == 5) {
            left = sn[i];
            continue;
        } else if (right == 5) {
            right = sn[i];
            continue;
        }
    }

    return 0;
}