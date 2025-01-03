// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/solutions/5792415/video-using-two-pointers-coding-exercise/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        // Unique elements appears at most twice

        if ((int)nums.size() < 2) return (int)nums.size();

        int j = 2;
        for (int i = 2; i < (int)nums.size(); i++) {
            if (nums[i] != nums[j - 2]) {
                nums[j] = nums[i];
                j++;
            }
        }

        return j;
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