#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool check(int dir, int ptr, vector<int>& nums) {
        // returns true if the input combination is valid

        while ((ptr >= 0) && (ptr < nums.size())) {
            if (dir == 0) {
                // check left
                if (nums[ptr] == 0)
                    ptr--;
                else {
                    (nums[ptr])--;
                    dir = !dir;
                    ptr++;
                }
            }
            // if (dir == 1) {
            else {
                // check right
                if (nums[ptr] == 0)
                    ptr++;
                else {
                    (nums[ptr])--;
                    dir = !dir;
                    ptr--;
                }
            }
        }
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] != 0) return false;
        }
        return true;
    }
    int countValidSelections(vector<int>& nums) {
        // for(auto v: nums) cout << v << " ";
        // cout << "\n";
        int n = 0;
        int validSolutions = 0;
        while (n < (int)nums.size()) {
            if (nums[n] == 0) {
                int dir = 0;
                while (dir < 2) {
                    vector<int> tmpnums = nums;
                    int isValid = check(dir, n, tmpnums);
                    // if (check(dir, n, tmpnums) == true) validSolutions++;
                    if ((isValid) == true) validSolutions++;
                    dir++;
                }
                n++;
            } else {
                n++;
            }
        }
        return validSolutions;
    }
};

int main() {
    auto a = freopen("input1.txt", "r", stdin);
    Solution sol;
    int n = 0;
    vector<int> arr;
    cin >> n;

    int temp;
    while (n--) {
        cin >> temp;
        arr.push_back(temp);
    }
    // for (int i =0;i<n;i++) cin >> arr[n];
    // sol.countValidSelections(arr);

    // cout << sol.check(0, 3, arr) << "\n";
    cout << sol.countValidSelections(arr) << "\n";

    // cout

    return 0;
}