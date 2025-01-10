#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Sort the arrays based on the length of elements

        // For each array of the same length
        // Check if the element after it is the same length
        // check if both of them are anagrams

        // Make a hashmap from each letter to the number of times it appears

        // Compare the hashmaps

        // If equal add the string to the current array
    }
};

int main() {
    if (!freopen("input.txt", "r", stdin)) cout << "There was an error opening input.txt";
    Solution sol;

    // Read strings of arrays
    int n = 0;
    vector<string> inp;
    cin >> n;
    cout << "n: " << n << "\n";
    string temp;
    getline(cin, temp);
    while (n--) {
        getline(cin, temp);
        inp.push_back(temp);
    }

    // for (int i = 0; i < (int)inp.size(); i++) {
    //     cout << inp[i] << " ";
    // }
    // cout << "\n";

    return 0;
}