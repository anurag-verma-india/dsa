// Implemented this answer
// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/solutions/5224249/efficient-easy-to-understand-c-code-beats-100

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            if (nums[i - 1] > nums[i]) count++;
        }
        if (nums[n - 1] > nums[0]) count++;

        if (count <= 1) return true;
        return false;
    }
};

int main() {
    if (!freopen("input.txt", "r", stdin)) cout << "There was an error opening input.txt";
    Solution sol;

    // Read array from stdin
    int n = 0;
    vector<int> arr;
    cin >> n;
    int temp;
    while (n--) {
        cin >> temp;
        arr.push_back(temp);
    }

    cout << sol.check(arr) << "\n";

    return 0;
}