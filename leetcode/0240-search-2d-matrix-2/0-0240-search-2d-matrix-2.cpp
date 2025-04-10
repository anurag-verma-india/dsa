// working, Not optimal
// https://leetcode.com/problems/search-a-2d-matrix-ii/
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"

/*
Input:
    2d int vector:
        each row and column are sorted in non-descending order
    int: target element

Output:
    boolean: true if the element in present in the array

Approach:

    for each matrix
    do binary search for the target in that matrix

---
Complexity:

Time:

Auxilary Space:

*/

class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l, r, md;  // left right middle

        for (int i = 0; i < m; i++) {
            l = 0, r = n - 1;
            while (l <= r) {
                md = l + (r - l) / 2;

                if (matrix[i][md] == target) {
                    return true;
                } else if (matrix[i][md] < target) {
                    l = md + 1;
                } else {
                    r = md - 1;
                }
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

    for (vector<int> v : arr_2d) {
        for (int n : v) cout << n << " ";
        printf("\n");
    }
    printf("target: %d\n", target);

    Solution sol;
    cout << "Ans: " << sol.searchMatrix(arr_2d, target) << "\n";
}