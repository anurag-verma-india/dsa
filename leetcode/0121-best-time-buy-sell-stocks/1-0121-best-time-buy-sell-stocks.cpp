// beats T 100, M 61
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

    for each price
        if it's lower then the previous lowest price update previous_lowest
        otherwise update the max profit by keeping max between that and current day potential profit

---
complexity
time

space
*/

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int lowest_price = prices[0];
        int max_profit = 0;

        for (int i = 1; i < n; i++) {
            if (prices[i] < lowest_price) {
                lowest_price = prices[i];
            }
            //  else {
            max_profit = max(max_profit, prices[i] - lowest_price);
            // }
        }
        return max_profit;
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