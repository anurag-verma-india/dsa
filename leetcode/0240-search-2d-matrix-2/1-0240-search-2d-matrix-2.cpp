// Beats 69% in time, 67% in memory
// https://leetcode.com/problems/search-a-2d-matrix-ii/solutions/66140/my-concise-omn-java-solution-by-chicm-h3tz/
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
    Start in the top right element
    if the element is target return
    if the element is greater than current value move left
    (Since there is still a chance that the target can be somewhere left)
    if the element is smaller than current value move down
    (Since the columns are also sorted, so the value below this element is bound to be greater or equal)
    (And since the rows are also sorted the values after this bottom value are greater then this too,
    so target can't be there)

---
Complexity:

Time:

Auxilary Space:

*/

class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();  // m = row size, n = column size
        int v = 0, h = n - 1;                         // vertical & horizontal
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) cout << matrix[i][j] << " ";
        //     printf("\n");
        // }
        // printf("\n");
        while (v < m && h >= 0) {
            if (matrix[v][h] == target)
                return true;
            else if (matrix[v][h] > target)
                h--;  // move left
            else
                v++;  // move down
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
    int ans = sol.searchMatrix(arr_2d, target);
    cout << "Ans: " << ans << "\n";
}