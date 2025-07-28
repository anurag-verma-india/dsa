#include <bits/stdc++.h>
using namespace std;

void solve() {
    deque<int> dq;
    for (int i = 4; i <= 9; i++) {
        if (i % 2 == 0) {
            dq.push_front(i);
        } else {
            dq.push_back(i);
        }
    }

    for (auto x : dq) {
        cout << x << " ";
    }

    cout << endl;
}

int main() {
    solve();
    return 0;
}