#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    vector<int> vec1 = {1,2,3};
    vector<int> vec2 = {};

    int i  = 0;
    vec2.clear();
    for (auto v: vec1) {
        vec2.push_back(v);
        i++;
    }
    for(int i = 0;i < (int)vec2.size();i++) {
        cout << vec2[i] << ", ";
    }
    cout << "\n";
    
    return 0;
}