#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void rotate(vector<int>& nums, int k) {
        for (int i = 0; i < (int)nums.size(); i++) {
            cout << nums[i] << " ";
        }
        printf("\n");
        cout << k << "\n";
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
    cin >> k; //after the array

    sol.rotate(arr, 3);

    // cout << sol.removeDuplicates(arr) << "\n";
    // int new_size = sol.removeDuplicates(arr);
    // for (int i = 0; i < (int)new_size; i++) cout << arr[i] << " ";
    // printf("\n");

    return 0;
}