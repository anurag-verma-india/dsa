#include <bits/stdc++.h>
using namespace std;

int main() {
    try {
        throw "Some error";

    } catch (char const* e) {
        cout << "Caught " << e << endl;
    }

    return 0;
}