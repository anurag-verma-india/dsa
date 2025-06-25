#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;

    v.push_back(1);
    v.emplace_back(2);

    cout << v[0] << "\n";

    vector<pair<int, int>> vec;

    vec.push_back({1, 2});
    // vec.push_back(1);
    vec.emplace_back(3, 4);

    cout << vec[0].first << " " << vec[0].first << ", " << " " << vec[1].first << " " << vec[1].second << "\n";

    // 5 instances of 100 in vector v
    vector<int> v2(5, 100);

    for (int i = 0; i < 5; i++)
        cout << v2[i] << " ";
    cout << "\n";

    // Or use iterators to run this loop
    // vector<int>::iterator v2beg= v2.begin();
    for (int n = 0; v2.begin() + n < v2.end(); n++)
        cout << *(v2.begin() + n) << " ";
    cout << "\n";

    return 0;
}