#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a[] = {1, 9, 19, 8, 5};
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        if (i % 2 == 0) {
            sum += *(a + i);

        } else {
            sum -= *(a + i);
        }
    }
    cout << sum << endl;
}

int main() {
    solve();
    return 0;
}