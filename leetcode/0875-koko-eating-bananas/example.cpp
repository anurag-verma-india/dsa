#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a(3, -1);
    vector<int> b(a);

    a[0] = 1;
    b[0] = 2;
    for (int i = 0; i < 3; i++) cout << a[i] << " ";
    cout << "\n";
    for (int i = 0; i < 3; i++) cout << b[i] << " ";
    cout << "\n";

    return 0;
}