// https://leetcode.com/problems/rotate-array/solutions/6056598/0-ms-runtime-beats-100-user-confirm-step-duqx/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void rotate(vector<int>& nums, int k) {
        int n = (int)nums.size();
        if (n == 0) return;
        k %= n;  // so that always k < n
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
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

    sol.rotate(arr, k);
    for (int i = 0; i < (int)arr.size(); i++) {
        cout << arr[i] << " ";
    }
    printf("\n");

    return 0;
}