#include <bits/stdc++.h>
using namespace std;
// ***
// ***
// ***
int main() {
    int n;
    printf("Enter number of lines to print: ");
    // cout << scanf(" %d", &n) << "\n";
    cin >> n;
    // cin >> n;
    // cout << n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("*");
        }
        printf("\n");
    }
}