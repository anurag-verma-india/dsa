// https://github.com/neetcode-gh/leetcode/blob/main/cpp%2F0347-top-k-frequent-elements.cpp
// https://leetcode.com/problems/top-k-frequent-elements/solutions/6215447/java-100-easy-bucket-sort-solution-with-6jhy3/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Make a mapping from numer to it's frequency

        // Make buckets and insert each number at it's frequency in the index

        // Go from highest frequency bucket to lowest one
        // Adding all numbers found in a bucket to the result
        // Until the result is greater than or equal to the given k

        unordered_map<int, int> m;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            m[nums[i]]++;
        }

        vector<vector<int>> buckets(n + 1);

        for (auto it = m.begin(); it != m.end(); it++) {
            buckets[it->second].push_back(it->first);
        }
        // for (auto entry : m) {
        //     buckets[entry.second].push_back(entry.first);
        // }

        vector<int> result;
        for (int i = n; i >= 0; i--) {
            if ((int)result.size() >= k) break;
            if (!buckets[i].empty()) {
                result.insert(result.end(), buckets[i].begin(), buckets[i].end());
            }
        }
        return result;
    }
};

int main() {
    if (!freopen("input.txt", "r", stdin)) {
        cout << "There was a problem opening the input file";
        exit(1);
    }

    // Read array from stdin
    int n = 0;
    vector<int> arr;
    cin >> n;
    int temp;
    while (n--) {
        cin >> temp;
        arr.push_back(temp);
    }
    int k;
    cin >> k;

    Solution sol;

    vector<int> ans = sol.topKFrequent(arr, k);
    for (int n : ans) cout << n << " ";
    printf("\n");

    return 0;
}