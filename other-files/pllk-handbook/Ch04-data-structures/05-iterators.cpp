#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector <int> a = {1,2,3,4};
    cout << *(a.begin()) << "\n";
    cout << *(a.begin()-1) << "\n\n";
    for (int i = 0; i <= 20;i++) {
        cout << *(a.begin()-i) << "\n";
    }
    cout << "Forward counting \n";

    for (int i = 0; i <= 20;i++) {
        cout << *(a.begin()+i) << "\n";
    }
    return 0;
}