// working but with brute force
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_int.cpp"

/*
input
    int arr: prices
    array of prices on each day

output
    int: profit

approach:
    buy low sell high

    highest difference
    right - left
    (because you must buy before selling)
    ---
    Brute force approach

    keep the count of the max element
    Buy on day 1 sell on 2
        sell on 3
        sell on 4
        ...
        sell on n-1
    Buy on day 2 sell on 3
    ...
    Buy on day n-2 sell on n-1

    ---
    highest & lowest method
    find the lowest price in the array
    find the highest price in the array

    if lowest is before highest return the difference

    else find the second lowest price

    ---
    somewhat sliding window

    start from first element
    keep increasing the size of the window go till the last element
    start from second element, go till last
    and continue

---
complexity
time

space
*/

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // Brute force approach
        int mprofit = 0;
        for (int i = 0; i < n - 1; i++) {
            // 0 to n - 1
            for (int j = i + 1; j < n; j++) {
                mprofit = max(mprofit, prices[j] - prices[i]);
                cout << "";
            }
        }
        return mprofit;
    }
};

int main() {
    file_as_stdin("input.txt");
    // file_as_stdin("input2.txt");
    vector<int> int_vec = read_int();

    cout << "Size: " << int_vec.size() << "\n";

    Solution sol;
    int solution = sol.maxProfit(int_vec);

    cout << "Max profit: " << solution << "\n";
    return 0;
}