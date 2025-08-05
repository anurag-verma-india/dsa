#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int, string> um = {{1, "a"},
                                     {2, "b"},
                                     {3, "c"}};

    um.insert({4, "d"});

    // Finding the value associated with 2
    cout << um.at(4) << "\n";

    unordered_map<int, int> um2;

    um2.insert({1, 10});
    um2.insert({2, 20});

    cout << um2.at(1) << "\n";



    return 0;
}
