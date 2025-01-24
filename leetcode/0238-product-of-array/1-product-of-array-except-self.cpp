// not working
// https://leetcode.com/problems/product-of-array-except-self/description/

// https://leetcode.com/problems/product-of-array-except-self/solutions/5833007/video-looping-the-input-array-twice-by-n-tivu/
// https://github.com/neetcode-gh/leetcode/blob/main/cpp%2F0238-product-of-array-except-self.cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
        Solve in two passes
        calculate products of all the numbers below an index and add it to that index
        calculate products of all the numbers after an index and add it to that index
        (after multiplying that to the prefix array)
        */
        int n = nums.size();
        vector<int> ans;

        int postfix = 1;
        vector<int> postfix_a;
        // for (int i = n - 1; i >= 0; i--) {
        for (int i = 0; i < n; i++) {
            postfix_a.push_back(postfix);
            postfix *= nums[i];
        }

        int prefix = 1;
        // vector<int> prefix_a;
        for (int i = 0; i < n; i++) {
            ans.push_back(prefix * postfix_a[i]);
            prefix *= nums[i];
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