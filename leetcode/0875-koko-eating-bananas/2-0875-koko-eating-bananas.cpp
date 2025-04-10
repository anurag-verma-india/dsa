
// T 27 M 42
// Some optimizations from looking at other commons submissions
// https://leetcode.com/problems/koko-eating-bananas/
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_int.cpp"

/*
input:
    int vector: plies
        number of bananas in each pile

    int: hours
        number of hours to eat each pile

output:
    int: k
        min number of bananas to each in each pile

approach:
    Binary search

    Search space (speed): [1, max(piles)]
    (Since koko can only eat from 1 pile in an hour, at most he can eat all bananas in a pile)

    Binary search to find the minimum speed and return the minimum one
---
Complexity:

Time:

Space:

*/

class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1, r = *max_element(piles.begin(), piles.end()), k, result = r;
        while (l <= r) {
            long int hours = 0;
            k = l + (r - l) / 2;
            for (int i = 0; i < n; i++) {
                // hours += ceil((double)piles[i] / k);
                hours += piles[i] / k;
                if ((piles[i] % k) != 0) hours++;
            }
            if (hours <= h) {
                // This eating speed (k) works
                // result = min(result, k);
                if (result > k) result = k;
                r = k - 1;
            } else {
                l = k + 1;
            }
        }
        return result;
    }
};

int main() {
    file_as_stdin("input.txt");
    vector<int> int_vec = read_int();
    int hours;
    cin >> hours;
    // for (int n : int_vec) cout << n << " ";
    // printf("\nhours: %d\n", hours);
    // cout << INT_MAX << "\n";

    Solution sol;

    int k = sol.minEatingSpeed(int_vec, hours);
    cout << "(Solution) k: " << k << "\n";
}