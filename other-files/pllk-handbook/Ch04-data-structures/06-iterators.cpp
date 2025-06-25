#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> s = {1, 2, 3};
    s.insert(4);
    for (set<int>::iterator i = s.begin(); i != s.end(); i++)
    {
        cout << *i << "\n";
    }
    cout << endl;
    for (auto i = s.begin(); i != s.end(); i++)
    {
        cout << *i << "\n";
    }
    return 0;
}