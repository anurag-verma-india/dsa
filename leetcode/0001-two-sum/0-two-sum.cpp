#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;

        for (int i = 0; i < (int)nums.size(); i++) {
            for (int j = i; j < (int)nums.size(); j++) {
                if (i != j) {
                    if (nums[i] + nums[j] == target) {
                        ans.push_back(i);
                        ans.push_back(j);
                    }
                }
            }
        }
        return ans;
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

    // sol.rotate(arr, k);
    // for (int i = 0; i < (int)arr.size(); i++) {
    //     cout << arr[i] << " ";
    // }
    // printf("\n");

    return 0;
}