
// https://leetcode.com/problems/two-sum/description/
#include <bits/stdc++.h>
using namespace std;
/*
Given:
    int Array: nums
    int: Target

Return:
    Indicies of two elements in the input array that add up to the target

Approach:

Make a map, to keep track of all elements' indices

loop through each element
check if the diff b/w current element and target is in the map
If yes then return the *indices* of current element and the element from the map
Otherwise add the current element to the map

*/

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> prev_map;  // number -> index

        for (int i = 0; i < n; i++) {
            int diff = target - nums[i];

            if (prev_map.find(diff) != prev_map.end()) return {prev_map[diff], i};

            prev_map[nums[i]] = i;
        }
        return vector<int>(1, -1); // Should not happen
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