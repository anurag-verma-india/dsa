// https://leetcode.com/problems/group-anagrams/

// sol.groupAnagrams should return a vector of vectors
// Each vector in that vector has all the anagrams grouped together

#include <bits/stdc++.h>
using namespace std;

// Solve the question then write down it's explanation

// Create a map from sorted representation of each string to a array (vector) of strings themselves

// This way each string that has the same characters will have the same key in the map
// (and thus will be in the same mapped array)

// Now we don't care about the keys in this map
// So make a new vector (array) and add each value vector in the map to it

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for (string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            // cout << key << " --> " << s << "\n";
            mp[key].push_back(s);
        }

        // Printing all the entries
        // for (auto entry : mp) {
        //     cout << entry.first << " --> ";
        //     for (auto st : entry.second) {
        //         cout << st << " ";
        //     }
        //     cout << "\n";
        // }

        for (auto entry : mp) {
            ans.push_back(entry.second);
        }
        // vector<vector<string>> ans;
        return ans;
    }
};

int main() {
    if (!freopen("input.txt", "r", stdin)) {
        cout << "There was a problem opening the input file";
        exit(1);
    }

    // Read strings of arrays
    int n = 0;
    vector<string> inp;
    cin >> n;
    // cout << "n: " << n << "\n";
    string temp;
    getline(cin, temp);
    while (n--) {
        getline(cin, temp);
        inp.push_back(temp);
    }

    Solution sol;

    // sol.groupAnagrams(inp);
    vector<vector<string>> solution = sol.groupAnagrams(inp);
    for (auto vec : solution) {
        for (auto st : vec) cout << st << " ";
        printf("\n");
    }

    return 0;
}
