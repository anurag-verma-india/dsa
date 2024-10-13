#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    vector<int> b(10, 100);
    v.push_back(5);
    v.push_back(2);
    cout << v.back() << "\n";

    for (int i = 0; i < b.size(); i++)
        cout << b[i] << " (" << i << ") ";
}