#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool check(vector<int>& nums) {
        int sind = 0;  // index of smallest number in array
        for (int i = 0; i < (int)nums.size(); i++) {
            // Find the smallest number in array
            // cout << nums[i] << " ";
            if (nums[i] <= nums[sind]) sind = i;
        }

        vector<int> nums_from_smallest;  // nums, but from sind to sind-1
        for (int i = sind; i < (int)nums.size(); i++) {
            nums_from_smallest.push_back(nums[i]);
        }
        for (int i = 0; i < sind; i++) {
            nums_from_smallest.push_back(nums[i]);
        }

        // Check if the array is not sorted
        for (int i = 0; i < (int)nums.size() - 1; i++) {
            if (nums_from_smallest[i] > nums_from_smallest[i + 1]) return false;
        }
        return true;
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