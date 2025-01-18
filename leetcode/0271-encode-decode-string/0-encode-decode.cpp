#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {

    }

    vector<string> decode(string s) {

    }
};

int main() {
    if (!freopen("input.txt", "r", stdin)) {
        cout << "There was a problem opening the input file";
        exit(1);
    }

    // Read array from stdin
    int n = 0;
    vector<int> arr;
    cin >> n;
    int temp;
    while (n--) {
        cin >> temp;
        arr.push_back(temp);
    }
    int k;
    cin >> k;

    Solution sol;

    vector<int> ans = sol.topKFrequent(arr, k);
    for (int n : ans) cout << n << " ";
    printf("\n");

    return 0;
}