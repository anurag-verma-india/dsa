// Time: Beats 100%, Space beats: 7%
// https://leetcode.com/problems/search-a-2d-matrix/
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"

/*
Input:
    2d int vector: vector of vectors with non-descending order elements (if flattened)
    int: target element

    Time complexity: must have O(log (m*n))
    [m = outer vector len, n = each inner vec len]

Output:
    boolean: true if the element in present in the array

Approach:

    Starting element is smallest in each vec
    Ending element is greatest in each vec

    Seach for the inner vector with following properties
        - ending element >= target
        - starting element is <= target

    Search this vec with binary search

    if this inner vec is found binary search it's elements
---
Complexity:

Time:
    O(log_2 m) + [outer search size halves at each step]
    O(log_2 n) [inner search size halves at each step]

Auxilary Space:
    O(1) [fixed number of variables independent of inp size (8)]
*/

class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        // left, right, middle
        int oul = 0, our = m - 1, oum;  // ou = outer
        int inl = 0, inr = n - 1, inm;  // in = inner

        while (oul <= our) {
            oum = oul + (our - oul) / 2;
            if (matrix[oum][inl] <= target && matrix[oum][inr] >= target) {
                // This is the target matrix
                while (inl <= inr) {
                    inm = inl + (inr - inl) / 2;
                    if (matrix[oum][inm] == target) {
                        return true;
                    } else if (matrix[oum][inm] < target) {
                        inl = inm + 1;
                    } else {
                        inr = inm - 1;
                    }
                }
                break;
            } else if (matrix[oum][inl] > target) {
                our = oum - 1;
            } else {
                oul = oum + 1;
            }
        }
        return false;
    }
};

int main() {
    file_as_stdin("input.txt");
    // vector<int> int_vec = read_int();

    int m, n, tmp, target;
    cin >> m;  // Total elements in outer vector
    cin >> n;  // Total element in each inner vector
    vector<vector<int>> arr_2d(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            arr_2d[i][j] = tmp;
        }
    }

    cin >> target;

    // for (vector<int> v : arr_2d) {
    //     for (int n : v) cout << n << " ";
    //     printf("\n");
    // }

    Solution sol;
    cout << "Ans: " << sol.searchMatrix(arr_2d, target) << "\n";
}