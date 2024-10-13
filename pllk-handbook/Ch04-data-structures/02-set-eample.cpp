#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> s;
    s.insert(2);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.erase(2);

    cout << "Size of set s is " << s.size() << ", 2 occurs " << s.count(2) << " times"
                                                                              "\n";

    for(auto elem: s) {
        cout << elem<< " ";
    }
    cout << "\n";

    return 0;
}