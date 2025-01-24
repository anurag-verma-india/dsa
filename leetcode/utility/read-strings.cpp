#include <bits/stdc++.h>
using namespace std;

int main() {
    // input.txt as stdin
    if (!freopen("input.txt", "r", stdin)) {
        cout << "There was a problem opening the input file";
        exit(1);
    }
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
    // cout << "n: " << n << "\n";
    string temp;
    getline(cin, temp);
    while (n--) {
        getline(cin, temp);
        inp.push_back(temp);
    }

    // inp is the array of strings
    return 0;
}
