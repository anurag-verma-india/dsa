// Solved
// https://leetcode.com/problems/two-sum/solutions/5679696/easiest-detailed-explanation-with-image-4i49g/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int> nums, int k) {
        unordered_map<int, int> prev_map;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int diff = k - nums[i];

            // check if index already exists in the map
            // (i.e. if the .find() method doesn't return the lastElement+1 iterator)
            if (prev_map.find(diff) != prev_map.end()) {
                return {prev_map[diff], i};
                // or
                // return {prev_map.at(diff), i};
            }
            // prev_map.insert({nums[i], i});
            // or
            prev_map[nums[i]] = i;
        }
        return vector<int>(1, -1);
    }
};

int main() {
    if (!freopen("input.txt", "r", stdin)) cout << "There was an error opening input.txt";
    Solution sol;

    // Read array from stdin
    int n = 0, k;
    vector<int> arr;
    cin >> n;
    int temp;
    while (n--) {
        cin >> temp;
        arr.push_back(temp);
    }
    cin >> k;  // after the array

    vector<int> ans = sol.twoSum(arr, k);
    for (int num : ans) cout << num << " ";
    printf("\n");

    return 0;
}