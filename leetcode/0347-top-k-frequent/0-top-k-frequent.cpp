// https://leetcode.com/problems/top-k-frequent-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numfreq;
        for (int n : nums) {
            numfreq[n]++;
        }
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

    return 0;
}