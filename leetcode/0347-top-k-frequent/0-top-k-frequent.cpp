// not working
// https://leetcode.com/problems/top-k-frequent-elements/description/
// return k most frequent elements

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // return true if second value of first element is smaller

    static bool comp(pair<const int, int> p1, pair<const int, int> p2) return p1.second < p2.second;

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> mp;
        vector<pair<const int, int>> mapVec;

        // Map each number to it's frequency
        for (auto num : nums) {
            mp[num]++;
        }

        for (pair<const int, int> entry : mp) {
            mapVec.push_back(entry);
            cout << entry.first << " --> " << entry.second << "\n";
        }

        // for (auto entry : mp) cout << entry.first << " ---> " << entry.second << "\n";

        // Sort the mapping by it's second element

        // call sort with a callback function that

        // Add the k most frequent elements in ans

        // -----------------------

        // Create a vector of pairs (mapping from elements to frequency)

        // sort according to the second element
        //
        // sort(mapVec.begin(), mapVec.end(), comp);
        sort(mapVec.begin(), mapVec.end());

        // return the first k elements
        //
        for (auto a : mapVec) {
            ans.push_back(a.first);
        }
        // -----test
        // cout << comp(mapVec[0], mapVec[1]);

        return ans;
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