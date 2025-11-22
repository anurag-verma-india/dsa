#include<bits/stdc++.h>
using namespace std;

int main () {
    // Single word (space separated)
    // Example input:
    // Anurag
    // string s;
    // cin >> s;
    // cout << s;

    // Single line string
    // Example input: 
    // Anurag Verma
    // string s;
    // getline(cin, s);
    // cout << s << endl;

    // Number then string
    // Example input:
    // 1
    // Anurag Verma
    string s;
    int n;
    cin >> n;
    cin.ignore();
    getline(cin, s);
    cout << n << " " << s << endl;
    
    return 0;
}