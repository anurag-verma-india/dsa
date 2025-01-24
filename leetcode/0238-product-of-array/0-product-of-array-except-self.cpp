// Doesn't count as solved
// brute force

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return vector<int>({nums[0]});
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            int p = 1;
            for (int j = 0; j < n; j++) {
                if (i != j) p *= nums[j];
            }
            ans.push_back(p);
        }
        return ans;
    }
};

int main() {
    // input.txt as stdin
    if (!freopen("input.txt", "r", stdin)) {
        cout << "There was a problem opening the input file";
        exit(1);
    }
    // Read array from stdin

    int n = 0;
    vector<int> inp;
    cin >> n;
    int temp;
    while (n--) {
        cin >> temp;
        inp.push_back(temp);
    }
    // inp is the array of strings

    Solution sol;

    // Passing empty array
    // vector<int> a = {};
    // vector<int> ans = sol.productExceptSelf(a);

    vector<int> ans = sol.productExceptSelf(inp);
    cout << "Returned vector size: " << ans.size() << "\n";
    for (int i = 0; i < (int)ans.size(); i++) cout << ans[i] << " ";
    cout << "\n";

    return 0;
}