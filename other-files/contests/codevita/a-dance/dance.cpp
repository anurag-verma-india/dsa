// https://www.geeksforgeeks.org/operators-in-cpp/

#include <bits/stdc++.h>
using namespace std;

int main() {
    // declarations
    int n;
    vector<string> s;

    // inputs
    cin >> n;
    while (n--) {
        string tmp;
        cin >> tmp;
        s.push_back(tmp);
    }

    // operations
    string hori = "";
    string vert = "";
    int ct = 0;

    cout << "\n";
    for (int i = 0; i < (int)s.size(); i++) {
        // cout << s[i] << " ";
        if ((vert == "") && ((s[i] == "left") || (s[i] == "right"))) {
            vert = s[i];
            continue;
        }
        if ((hori == "") && ((s[i] == "up") || (s[i] == "down"))) {
            hori = s[i];
            continue;
        }
        if ((s[i] != "left") && (s[i] != "right") && (s[i] != hori)) {
            hori = s[i];
            ct += 1;
        }
        if ((s[i] != "up") && (s[i] != "down") && (s[i] != vert)) {
            vert = s[i];
            ct += 1;
        }
        // cout << hori << " ";
        // cout << vert << " ";
        // cout << "\n";
    }
    cout << ct << "\n";
}