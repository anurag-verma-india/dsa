#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Simple pairs
    pair<int, int> p = {1, 3};
    cout << p.first << " " << p.second << "\n";

    // Nested Pairs
    pair<int,pair<int,int>> p2 = {1,{1,2}};
    cout << p2.first << " " << p2.second.first << " " << p2.second.second << "\n";

    // Pair arrays
    cout << "Array of pairs\n";
    pair<int,int> a[] = {{1,2},{3,4},{5,6},{7,8}};
    for (int i = 0;i < 4;i++) {
        cout << a[i].first << " " << a[i].second << "\n";
    }

    return 0;
}