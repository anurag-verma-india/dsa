#include <bits/stdc++.h>
using namespace std;
/*
input:
    string s: consisting of different number of * and #

output:
    int n: +ve if * > #
           -ve if * < #
           0 if * = #

Approach:
    pass through the string and keep a counter for hash and star
    at the end return star_count - hash_count
*/

class Solution {
   public:
    int match_star_and_hashes(string s) {
        int n = s.size();
        int hashes = 0;
        int stars = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '*') stars++;
            if (s[i] == '#') hashes++;
        }
        return stars - hashes;
    }
};

int main() {
    const string input_file = "04-input.txt";
    if(!freopen(input_file.c_str(), "r", stdin)) cout << "There was an error opening the input file " << input_file << endl;
    string s;
    getline(cin, s);

    

    Solution sol;
    int output = sol.match_star_and_hashes(s);

    cout << output << endl;

    return 0;
}