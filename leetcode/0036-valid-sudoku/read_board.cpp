// #include <bits/stdc++.h>

// #include "./read.cpp"
#include <string.h>

#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> read_board() {
    vector<vector<char>> board;

    for (int i = 0; i < 9; i++) {
        string line_str;
        getline(cin, line_str);
        vector<char> line_arr;

        for (int j = 0; j < 9; j++) {
            line_arr.push_back(line_str[j]);
        }
        board.push_back(line_arr);
        // for (int j = 0; j < 9; j++) {
        //     cout << board[i][j] << " ";
        // }
        // printf("\n");
    }
    return board;
}
