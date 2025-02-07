// https://leetcode.com/problems/valid-sudoku/description/

// Code: https://leetcode.com/problems/valid-sudoku/solutions/6108715/0-ms-runtime-beats-100-user-code-idea-al-awgv/
// Visuals: https://leetcode.com/problems/valid-sudoku/solutions/5272799/video-keep-number-we-found-and-find-dupl-4unj/
// LC: Beats 100%
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_board.cpp"

/*

For the box bitmap array use this formula: (row / 3) * 3 + (col / 3)

Explanation:

col -> 012 345 678
   012  0   1   2
   345  3   4   5
   678  6   7   8
    ^
    |
   row


How the code works:
Each each entry in the three arrays for each row, col and box group has a bitmap
each bitmap is used to keep track of each individual number that has appeared (0-8, 9 positions)
in the row, col, or box


Essentially
We scan the sudoku grid from left to right (inner loop, j)
and top to bottom (outer loop, i)

for each value we update the bitmap of the row it's in, the col, and the box it's in

if we ever encounter a value that we have already encountered previously in the same section
(i.e row, col, or box) we return false
otherwise if we reach the end without returning false,
we assume that the value grid is valid and we return true
*/

class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9] = {0}, col[9] = {0}, boxes[9] = {0};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '1';  // Converting (char) '1'-'9' to (int) 0-8
                int mask = 1 << num;
                int boxIndex = (i / 3) * 3 + (j / 3);

                if (row[i] & mask || col[j] & mask || boxes[boxIndex] & mask) {
                    return false;
                }

                row[i] |= mask;
                col[j] |= mask;
                boxes[boxIndex] |= mask;
            }
        }
        return true;
    }
};

int main() {
    file_as_stdin("input.txt");
    // vector<string> str = read_string();
    cout << string(10, '-') << "Sudoku" << string(10, '-') << "\n";
    vector<vector<char>> board = read_board();
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }

    Solution sol;
    cout << "Is valid: ";
    if (sol.isValidSudoku(board))
        cout << "yes\n";
    else
        cout << "no\n";

    // int n0= (int)'0';
    // int n1 = (int)'1';
    // int n2 = (int)'2';
    // cout << "0 in int " << n0 << "\n";
    // cout << "1 in int " << n1 << "\n";
    // cout << "2 in int " << n2 << "\n";

    // cout << "is digit .  "  << isdigit('.') << "\n";
}