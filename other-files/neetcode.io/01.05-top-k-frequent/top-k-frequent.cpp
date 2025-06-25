#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // It uses the fact that maps are implemented by balanced binary trees
    // So maps are already sorted when they are made
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> value_to_freq;
        vector<int> by_ascending_freq;
        for (auto ele : nums) {
            value_to_freq[ele] += 1;
        }
        // map<int, int> freq_to_value;
        // for (auto ele : value_to_freq) {
        //     freq_to_value[ele.second] = ele.first;
        // }
        vector<int> values_by_freq_vec;
        int count = 0;
        for (auto ele : value_to_freq) {
            if (count < k) {
                values_by_freq_vec.push_back(ele.first);
                // cout << ele.first << " ";
            }
            count++;
        }
        // cout << "\n";

        // Insert k of the most frequent values into the vector array
        // int count = 0;
        // for (auto ele : freq_to_value) {
        //     by_ascending_freq.push_back(ele.second);
        //     count++;
        // }
        // reverse(by_ascending_freq.begin(), by_ascending_freq.end());
        // vector<int> k_deseding_freq;
        // for (int i = 0; i < k; i++) {
        //     k_deseding_freq.push_back(by_ascending_freq[i]);
        // }
        return values_by_freq_vec;
    }
};

// class Solution {
//    public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         map<int, int> value_to_freq;
//         vector<int> k_most_freq;
//         vector<pair<int, int>> pair_by_freq;
//         for (auto ele : nums) {
//             value_to_freq[ele] += 1;
//         }
//         pair_by_freq.push_back(make_pair(0, 0));
//         for (auto x : value_to_freq) {
//             //     cout << x.first << " " << x.second << "\n";
//             for (int i = 0; i < k; i++) {
//                 if (i < pair_by_freq.size()) {
//                     if (x.second > pair_by_freq[i].second) {
//                         // pair<int,int> tmp_pair;
//                         // tmp_pair.first = x.first;
//                         // tmp_pair.second = x.second;
//                         pair_by_freq.insert(pair_by_freq.begin() + i, make_pair(x.first, x.second));
//                     }
//                 }
//             }
//         }
//         for (auto x : pair_by_freq) {
//             // sorted_by_freq.push_back(make_pair(x.first,x.second));
//             cout << x.first << " " << x.second << "\n";
//         }
//         return k_most_freq;
//     }
// }

int main() {
    if (!freopen("input.txt", "r", stdin)) cout << "There was an error opening input.txt\n";
    vector<int> vec;

    // get input
    int n;  // size of i/p arr
    int k;  // top k
    cin >> n;
    while (n--) {
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }
    cin >> k;

    // for (auto v : vec) cout << v << " ";
    // cout << "\n"
    //      << k << "\n";
    Solution sol;
    vector frequent_elements = sol.topKFrequent(vec, k);
    for (auto x : frequent_elements) cout << x << " ";
    cout << "\n";

    return 0;
}