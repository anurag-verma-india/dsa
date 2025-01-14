// Does not work (solved with help) (Solved in different file)

// https://leetcode.com/problems/group-anagrams/
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // vector<vector<string>> groupAnagrams(vector<string>& strs) {
    int groupAnagrams(vector<string>& strs) {
        // Sort the strings with their length
        stable_sort(strs.begin(), strs.end(), [](string a, string b) -> bool {
            if (a.size() != b.size()) return a.size() < b.size();
            return false;
        });

        for (auto st : strs) {
            cout << st << " ";
        }
        cout << "\n";

        // For each string of the same length calculate it's hashmap alphabet to num of appearances
        map<char, int> letterToNumAppear;

        for (int i = 0; i < (int)strs.size(); i++) {
            for (int j = 0; j < (int)strs[i].size(); j++) {
            }
        }

        // Compare the each hashmap to every other and make a array with the ones that match
        // Remove them from the original hashmap array

        // Add this array to a new array

        // Do this for every subsequent array
        return 0;
    }
};

int main() {
    if (!freopen("input.txt", "r", stdin)) cout << "There was an error opening input.txt";
    Solution sol;

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

    sol.groupAnagrams(inp);

    return 0;
}

// First approach
// --------------------------------
// Sort the arrays based on the length of elements

// For each array of the same length
// Check if the element after it is the same length
// check if both of them are anagrams

// Make a hashmap from each letter to the number of times it appears

// Compare the hashmaps

// If equal add the string to the current array