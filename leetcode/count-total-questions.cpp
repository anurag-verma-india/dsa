#include <bits/stdc++.h>
using namespace std;

int count_opening_square_brackets(string s) {
    int count = 0;
    for (auto st : s) {
        if (st == '[') count++;
    }
    return count;
}

int main() {
    // freopen("01-index.md", "r", stdin);
    int consecutive_blank_lines = 0;
    int total_problems_solved = 0;

    string line;
    while (consecutive_blank_lines < 4) {
        line.clear();
        cin >> line;
        // cout << line << "\n";
        if (line == "") {
            // cout << "\nblank line\n";
            consecutive_blank_lines++;
            continue;
        }
        total_problems_solved += count_opening_square_brackets(line);
    }
    cout << "Total problems solved (or rather total [): " << total_problems_solved << "\n";
}