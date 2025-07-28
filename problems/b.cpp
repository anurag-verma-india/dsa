
#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int main() {
    string str = "hello world";

    transform(str.begin(), str.begin() + 6, str.begin(), ::toupper);
    cout << str << endl;
    

}