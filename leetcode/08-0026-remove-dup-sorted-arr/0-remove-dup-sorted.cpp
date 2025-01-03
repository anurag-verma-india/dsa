#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        // Make a new array
        vector<int> narr;  // new array

        // narr[0] = nums[0];
        narr.push_back(nums[0]);

        // Add every element to new one after checking if it's not same as existing one
        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                narr.push_back(nums[i]);
            }
        }
        // replace the passed array's elements with new array's
        for (int i = 0; i < (int)narr.size(); i++) nums[i] = narr[i];

        // return the size of the new array
        return narr.size();
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

    // cout << sol.removeDuplicates(arr) << "\n";
    int new_size = sol.removeDuplicates(arr);
    for (int i = 0; i < (int)new_size; i++) cout << arr[i] << " ";
    printf("\n");

    return 0;
}