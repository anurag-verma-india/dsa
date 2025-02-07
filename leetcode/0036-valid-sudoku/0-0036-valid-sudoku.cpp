// https://leetcode.com/problems/valid-sudoku/description/
// Works but not optimal
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_board.cpp"

/*
sections are each row, each column, all 3x3 squares

for each section check if it is valid

check if each section is valid by
checking if current char is already in the temp array (if yes return false)
if not add each character you encounter to the temp array
*/



class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Checking rows
        for (int i = 0; i < 9; i++) {
            vector<char> temp_row;
            for (int j = 0; j < 9; j++) {
                char temp_c4row = board[i][j];
                if (isdigit(temp_c4row)) {
                    if (find(temp_row.begin(), temp_row.end(), temp_c4row) != temp_row.end()) {
                        // A char is repeated
                        return false;
                    } else {
                        // Not already in the array
                        temp_row.push_back(temp_c4row);
                    }
                }
            }
        }
        // Checking columns
        for (int i = 0; i < 9; i++) {
            vector<char> temp_col;
            for (int j = 0; j < 9; j++) {
                char temp_c4col = board[j][i];
                if (isdigit(temp_c4col)) {
                    if (find(temp_col.begin(), temp_col.end(), temp_c4col) != temp_col.end()) {
                        // A char is repeated
                        return false;
                    } else {
                        // Not already in the array
                        temp_col.push_back(temp_c4col);
                    }
                }
            }
        }

        for (int k = 0; k < 9; k++) {
            int ki, kj;
            switch (k) {
                case 0: {
                    ki = 0;
                    kj = 0;
                    break;
                }
                case 1: {
                    ki = 0;
                    kj = 3;
                    break;
                }
                case 2: {
                    ki = 0;
                    kj = 6;
                    break;
                }
                case 3: {
                    ki = 3;
                    kj = 0;
                    break;
                }
                case 4: {
                    ki = 3;
                    kj = 3;
                    break;
                }
                case 5: {
                    ki = 3;
                    kj = 6;
                    break;
                }
                case 6: {
                    ki = 6;
                    kj = 0;
                    break;
                }
                case 7: {
                    ki = 6;
                    kj = 3;
                    break;
                }
                case 8: {
                    ki = 6;
                    kj = 6;
                    break;
                }
            }
            vector<char> temp;
            for (int i = ki; i < ki + 3; i++) {
                for (int j = kj; j < kj + 3; j++) {
                    cout << i << j << " ";
                    char temp_c = board[i][j];
                    if (isdigit(temp_c)) {
                        if (find(temp.begin(), temp.end(), temp_c) != temp.end()) {
                            // A char is repeated
                            return false;
                        } else {
                            // Not already in the array
                            temp.push_back(temp_c);
                        }
                    }
                }
                cout << "\n";
            }
            cout << "\n";
        }

        return true;
    }
};

int main() {
    file_as_stdin("input.txt");
    // vector<string> str = read_string();
    vector<vector<char>> board = read_board();
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }

    Solution sol;
    cout << sol.isValidSudoku(board) << "\n";

    // cout << "is digit .  "  << isdigit('.') << "\n";
}