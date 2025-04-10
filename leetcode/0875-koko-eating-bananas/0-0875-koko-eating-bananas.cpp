// Does not work
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

    brute force
    start with k = 1 & increment by 1

    for each value of k
    (in each hour deduct k from first pile until it's <= 0)
    or make this pile, pile[i] % k after deducting pile[i] / k (int) from h
    if h is > 0 then move to the next pile

    if we make all piles <= 0 and h >= 0 then return that k
    otherwise continue

---
Complexity:

Time:

Space:

*/

class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size(), k = 1;
        for (int i = 0; i < INT_MAX; i++) {
            int temp_h = h;
            vector<int> temp_piles(piles);
            for (int j = 0; i < n; j++) {
                int hrs = temp_piles[j] / k;
                if ((temp_piles[j] % k) > 0) hrs++;
                temp_h -= hrs;
                if (temp_h <= 0) break;
            }
            if (temp_h >= 0) return k;
            k++;
        }
        return 0;
    }
};

int main() {
    file_as_stdin("input.txt");
    vector<int> int_vec = read_int();
    int hours;
    cin >> hours;
    for (int n : int_vec) cout << n << " ";
    printf("\nhours: %d\n", hours);
    // cout << INT_MAX << "\n";

    Solution sol;

    int k = sol.minEatingSpeed(int_vec, hours);
    cout << "k: " << k << "\n";
}