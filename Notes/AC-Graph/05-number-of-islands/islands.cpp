// s: 16.72mb, 57%; t: 26md, 61%
#include <iostream>
#include <vector>
using namespace std;

void readFromStdin(const string filePath) {
    if (!freopen(filePath.c_str(), "r", stdin)) {
        cerr << "There was a problem in opening the file '" << filePath << "'\n";
        exit(1);
    }
}

vector<vector<char>> readGrid() {
    int n, m;
    char temp;
    cin >> n >> m;
    cout << "n: " << n << ", m: " << m << endl;
    vector<vector<char>> grid(n, vector<char>(m, '0'));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> temp;
            grid[i][j] = temp;
        }
    }
    return grid;
}

class Solution {
    void countIslandsDFS(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited, int n, int m) {
        /*
        If it is a invalid cell, visited cell, or non land cell, then skip it

        otherwise try to visit top, right, bottom, and left of it's cells
        */
        if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || grid[i][j] != '1') {
            return;
        }
        visited[i][j] = true;
        // top
        countIslandsDFS(i - 1, j, grid, visited, n, m);
        // right
        countIslandsDFS(i, j + 1, grid, visited, n, m);
        // bottom
        countIslandsDFS(i + 1, j, grid, visited, n, m);
        // left
        countIslandsDFS(i, j - 1, grid, visited, n, m);
    }

   public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    countIslandsDFS(i, j, grid, visited, n, m);
                    islands++;
                }
            }
        }

        return islands;
    }
};

int main() {
    readFromStdin("intput.txt");
    vector<vector<char>> grid = readGrid();

    int n = grid.size();
    int m = grid[0].size();
    cout << "-------------" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    Solution sol;
    int islands = sol.numIslands(grid);

    cout << "Number of islands in this grid are: " << islands << "\n";

    return 0;
}