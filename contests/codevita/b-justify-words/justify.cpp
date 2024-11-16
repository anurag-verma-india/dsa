#include <bits/stdc++.h>
using namespace std;

int justify_words(int num_words, int num_lines, int max_line_len, vector<int> word_sz_lst) {
    int ptr = 0;
    for (int i = 0; i < num_lines; i++) {
        if (ptr == ((int)word_sz_lst.size() - 1)) {
            break;
        }
        int rem = max_line_len;
        while (word_sz_lst[ptr] <= rem) {
            rem = rem - word_sz_lst[ptr] - 1;  // -1 for space character
            ptr++;
        }
    }
    return ptr + 1;
};

int main() {
    // init
    int k = 0, m = 0, n = 0;
    // vector<string> lst;
    vector<int> lvec;

    // get inputs
    cin >> k;
    string word;

    for (int i = 0; i < k; i++) {
        cin >> word;
        // lst.push_back(word);
        lvec.push_back(word.size());
    }

    cin >> n;
    cin >> m;

    // operations
    sort(lvec.begin(), lvec.end());
    cout << justify_words(k, n, m, lvec) << "\n";

    return 0;
}